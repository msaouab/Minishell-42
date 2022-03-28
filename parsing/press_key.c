/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:29 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:44 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	re_alloc(t_his **list, int rp)
{
	int		len;
	int		i;
	char	*tmp;

	tmp = NULL;
	len = 0;
	while ((*list)->input[len])
		len++;
	tmp = (char *)malloc(len + 2);
	i = -1;
	while (++i < len)
		tmp[i] = (*list)->input[i];
	free((*list)->input);
	tmp[i] = rp;
	tmp[i + 1] = '\0';
	(*list)->input = (char *)malloc(len + 2);
	i = -1;
	while (tmp[++i])
		(*list)->input[i] = tmp[i];
	(*list)->input[i] = '\0';
	free(tmp);
}

void	print_caract(t_his **list, int rp)
{
	if (!(*list)->input)
	{
		(*list)->input = (char *)malloc((*list)->cursor + 2);
		(*list)->input[(*list)->cursor] = rp;
		(*list)->input[(*list)->cursor + 1] = '\0';
	}
	else
		re_alloc(list, rp);
	ft_putstr_fd((*list)->input + (*list)->cursor, 1);
	(*list)->cursor++;
}

void	func_cont_rdl(int rp, t_var *var, t_his *his, t_his **list)
{
	if (rp > 31 && rp < 127)
		print_caract(list, rp);
	else if (rp == KEY_DEL)
		func_press_del(list);
	else if (rp == KEY_U)
		func_press_up(list);
	else if (rp == KEY_DW)
		func_press_down(list);
	else if (rp == CTRL_C)
		func_cntrl_c(his, var, list);
	else if (rp == CTRL_D)
		func_cntrl_d(var, list);
}
