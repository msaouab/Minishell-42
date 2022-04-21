/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:02:53 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 12:40:15 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/minishell.h"

void	ft_unset(t_var *var)
{
	t_env	*current;
	char	*tmp;
	int		i;

	i = 0;
	while (var->prs->args[i])
	{
		tmp = var->prs->args[i];
		current = var->head_env;
		while (current && ft_strncmp(current->key, tmp, ft_strlen(tmp)))
			current = current->next;
		if (current)
		{
			free(current->key);
			free(current->value);
			current->key = NULL;
			current->value = NULL;
		}
		i++;
	}
	var->status = 0;
}
