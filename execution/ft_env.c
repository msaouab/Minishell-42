/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:54:24 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/02 21:10:14 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	chenv(t_var *var, char *file)
{
	t_env	*current;

	current = var->head_env;
	while (current)
	{
		if (ft_strncmp("PWD", current->key, 3) == 0)
			current->value = file;
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
