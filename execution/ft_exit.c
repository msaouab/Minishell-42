/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:13:09 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/13 16:39:03 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_var *var)
{
	if (var->prs->args[1] && var->prs->args[2])
		ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 1);
	else if (var->prs->args[1] && (is_digit(var->prs->args[1]) == 0))
	{
		ft_putstr_fd("exit\nminshell: exit: ", 1);
		ft_putstr_fd(var->prs->args[1], 1);
		ft_putstr_fd(": numeric argument required\n", 1);
		exit(0);
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
}