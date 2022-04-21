/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:25 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 14:44:23 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/minishell.h"

void	init_symbol(t_var *var)
{
	var->double_q = 0;
	var->single_q = 0;
	var->semi_colomn = 0;
	var->redir_left = 0;
	var->redir_right = 0;
	var->redir_double = 0;
	var->pipe = 0;
	var->back_sl = 0;
	var->error = 0;
	var->step = 0;
	var->line = NULL;
	var->split_sc = NULL;
	var->split_pip = NULL;
	var->prs = NULL;
	var->prstail = NULL;
	var->exit = 0;
}

void	ft_subcmd(t_parser *prs, t_var *var, int *j)
{
	prs = (t_parser *)malloc(sizeof(t_parser));
	prs->file_head = NULL;
	prs->next_prs = NULL;
	add_prs_tonode(var, prs);
	search_file(var, j);
	search_cmd_args(var, j);
}

void	fill_command(t_var *var, char **env)
{
	t_parser	*prs;
	int			i;
	int			j;

	prs = NULL;
	i = -1;
	var->split_sc = ft_split(var->line, ';');
	var->old_out = dup(STDOUT_FILENO);
	var->old_in = dup(STDIN_FILENO);
	while (var->split_sc[++i])
	{
		clear_line(var, &(var->split_sc[i]));
		free_list_cmd(var->prs, var);
		j = -1;
		var->split_pip = ft_split(var->split_sc[i], '|');
		while (var->split_pip[++j])
			ft_subcmd(prs, var, &j);
		execution(var, env);
		if (var->exit)
			break ;
	}
}

void	ft_newline(t_var *var, char *tmp)
{
	var->line = readline("minishell~> ");
	if (!var->line)
		exit(0);
	add_history(var->line);
	puts(var->line);
	tmp = var->line;
	var->line = ft_strtrim(var->line, " ");
	free(tmp);
}

int	main(int ac, char **av, char **env)
{
	t_var	var;
	char	*tmp;
	int		i;

	if (ac != 1)
		ft_multi_args(av[1]);
	tmp = NULL;
	init_env(&var, env);
	while (1)
	{
		i = -1;
		init_symbol(&var);
		ft_newline(&var, tmp);
		syntax_error(&var, i);
		if (var.error != 0)
		{
			var.error = 0;
			continue ;
		}
		fill_command(&var, env);
		ft_free(&var);
	}
	return (0);
}
