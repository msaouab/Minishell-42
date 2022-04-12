/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:54:24 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/08 22:34:43 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ch_pwd(t_var *var, char *home)
{
	t_env	*current;

	current = var->head_env;
	while (current)
	{
		if (ft_strncmp(current->key, "PWD", 3) == 0)
		{
			current->value = home;
		}
		current = current->next;
	}
}

void	ft_env(t_var *var)
{
	t_env	*current;

	current = var->head_env;
	while (current)
	{
		ft_putstr_fd(current->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(current->value, 1);
		ft_putstr_fd("\n", 1);
		current = current->next;
	}
}
