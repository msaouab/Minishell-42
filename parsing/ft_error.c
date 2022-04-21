/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:33 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 15:08:14 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/minishell.h"

void	hundel_error(int err, t_var *var)
{
	var->error = err;
	var->status = 258;
	free(var->line);
	var->line = NULL;
	if (err == TOKEN_RL)
		ft_putstr_fd("minishell:syntax error near unexpected token `<'\n", 2);
	else if (err == TOKEN_RR)
		ft_putstr_fd("minishell:syntax error near unexpected token `>'\n", 2);
	else if (err == TOKEN_DR)
		ft_putstr_fd("minishell:syntax error near unexpected token `>>'\n", 2);
	else if (err == TOKEN_SC)
		ft_putstr_fd("minishell:syntax error near unexpected token `;'\n", 2);
	else if (err == TOKEN_PIP)
		ft_putstr_fd("minishell:syntax error near unexpected token `|'\n", 2);
	else if (err == TOKEN_DPIP)
		ft_putstr_fd("minishell:syntax error near unexpected token `||'\n", 2);
	else if (err == NEW_LINE)
	{
		ft_putstr_fd("minishell:syntax error near unexpected ", 2);
		ft_putstr_fd("token `newline'\n", 2);
	}
	else if (err == TOKEN_DSC)
		ft_putstr_fd("minishell:syntax error near unexpected token `;;'\n", 2);
}

void	free_list_files(t_parser *prs)
{
	t_files	*curr;
	t_files	*next_node;

	curr = prs->file_head;
	next_node = NULL;
	while (curr)
	{
		next_node = curr->next;
		if (curr->file_name)
			free(curr->file_name);
		free(curr);
		curr = NULL;
		curr = next_node;
	}
	prs->file_head = NULL;
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	if (args)
		free(args);
}

void	free_list_cmd(t_parser *prs, t_var *var)
{
	t_parser	*curr;
	int			i;

	i = -1;
	curr = prs;
	if (var->split_pip)
	{
		while (var->split_pip[++i])
			free(var->split_pip[i]);
		free(var->split_pip);
	}
	while (curr)
	{
		var->prstail = curr->next_prs;
		free_args(curr->args);
		free_list_files(curr);
		free(curr);
		curr = NULL;
		curr = var->prstail;
	}
	var->prs = NULL;
}

void	ft_free_doble(char **str, char *s)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	free(s);
}
