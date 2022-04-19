/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:48:39 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/18 17:50:15 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(t_var *var)
{
	int	i;

	i = 1;
	if (ft_strncmp(var->prs->args[1], "-n", 2) == 0)
	{
		i++;
		while (var->prs->args[i])
		{
			ft_putstr_fd(var->prs->args[i], 1);
			if (var->prs->args[i + 1])
				ft_putstr_fd(" ", 1);
			i++;
		}
	}
	while (var->prs->args[i])
	{
		ft_putstr_fd(var->prs->args[i], 1);
		if (var->prs->args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
		if (!var->prs->args[i])
			ft_putstr_fd("\n", 1);
	}
}
