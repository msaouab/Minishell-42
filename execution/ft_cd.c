/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:47:12 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/02 21:12:40 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_home(t_var *var)
{
	t_env	*current;
	int		i;

	i = 0;
	current = var->head_env;
	while (current)
	{
		if (ft_strncmp("HOME", current->key, 4) == 0)
			return (ft_strdup(current->value));
		current = current->next;
	}
	return (NULL);
}

void	ft_cd(t_var *var)
{
	t_env	*old_pwd;
	char	*home;
	int		cd;
	int		i;

	i = 1;
	old_pwd = var->head_env;
	if (!var->prs->args[i] || (ft_strncmp("~", var->prs->args[i], 1) == 0))
	{
		home = get_home(var);
		if (!home)
			return ;
	}
	if (ft_strncmp("-", var->prs->args[i], 1) == 0)
	{
		
	}
	cd = chdir(home);
	if (cd < 0)
		printf("no such file or directory: %s\n", var->prs->args[i]);
	else
		chenv(var, home);
}