/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_readline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:41 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:51 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	func_cntrl_c(t_his *his, t_var *var, t_his **list)
{
	delete_node(var);
	his = create_node_hist();
	assign_list(var, list, his);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\033[1;32mminishell~>\033[0m", 1);
}

void	func_cntrl_d(t_var *var, t_his **list)
{
	if ((*list)->input)
		return ;
	ft_putstr_fd("exit", 1);
	exit(var->status);
}

void	func_press_del(t_his **list)
{
	if (!(*list)->cursor)
		return ;
	(*list)->cursor--;
	(*list)->input[(*list)->cursor] = 0;
	ft_putstr_fd("\033[1D\033[K", 1);
	if ((*list)->cursor == 0)
	{
		free((*list)->input);
		(*list)->input = NULL;
	}
}

void	func_press_up(t_his **list)
{
	if (!(*list)->prev)
		return ;
	(*list) = (*list)->prev;
	ft_putstr_fd("\r\033[0K", 1);
	ft_putstr_fd("\033[1;32mminishell~>\033[0m", 1);
	ft_putstr_fd((*list)->input, 1);
}

void	func_press_down(t_his **list)
{
	if (!(*list)->next)
		return ;
	*list = (*list)->next;
	ft_putstr_fd("\r\033[0K", 1);
	ft_putstr_fd("\033[1;32mminishell~>\033[0m", 1);
	ft_putstr_fd((*list)->input, 1);
}
