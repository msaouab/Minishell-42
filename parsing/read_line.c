/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:52:17 by mbelaman          #+#    #+#             */
/*   Updated: 2022/03/28 14:43:48 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	my_dll(t_var *var, t_his *list, char *input)
{
	t_his	*curr;
	t_his	*his;
	int		len;

	len = ft_strlen(list->input);
	his = (t_his *)malloc(sizeof(t_his));
	his->next = NULL;
	his->prev = NULL;
	his->cursor = list->cursor;
	his->input = ft_strdup(input);
	if (!var->head_his)
		var->head_his = his;
	else
	{
		curr = var->head_his;
		while (curr->next)
			curr = curr->next;
		his->prev = curr;
		curr->next = his;
	}
}

void	delete_node(t_var *var)
{
	t_his	*list;
	t_his	*prev;

	list = NULL;
	prev = NULL;
	list = var->head_his;
	while (list->next)
	{
		prev = list;
		list = list->next;
	}
	if (prev)
	{
		prev->next = NULL;
		free(list->input);
		free(list);
	}
	else
	{
		free(var->head_his->input);
		free(var->head_his);
		var->head_his = NULL;
	}
}

void	func_enter(t_his *list, t_var *var)
{
	char	*tmp;

	tmp = NULL;
	ft_putstr_fd("\n", 1);
	if (!list->input)
	{
		ft_putstr_fd("\033[1;32mminishell~>\033[0m", 1);
		return ;
	}
	var->line = ft_strdup(list->input);
	delete_node(var);
	if (var->line)
		my_dll(var, list, var->line);
}

void	read_line(t_var *var)
{
	t_his			*list;
	t_his			*his;
	struct termios	old_attr;
	int				rp;

	termios_config(&old_attr);
	his = create_node_hist();
	list = NULL;
	assign_list(var, &list, his);
	while (1)
	{
		rp = 0;
		read(0, &rp, 4);
		if (rp == KEY_EN)
		{
			func_enter(list, var);
			if (var->line == NULL)
				continue ;
			break ;
		}
		else
			func_cont_rdl(rp, var, his, &list);
	}
	old_attr.c_lflag |= (ISIG);
	tcsetattr(STDIN_FILENO, TCSANOW, &old_attr);
}
