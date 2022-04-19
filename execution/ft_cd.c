/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:10:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/18 23:20:19 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_home(t_var *var)
{
	t_env	*current;

	current = var->head_env;
	while (current)
	{
		if (ft_strncmp(current->key, "HOME", 4) == 0)
			return (ft_strdup(current->value));
		current = current->next;
	}
	return (NULL);
}

void	ft_cd(t_var *var)
{
	char	*home;
	int		cd;

	if (!(var->prs->args[1]))
		home = get_home(var);
	else
		home = ft_strdup(var->prs->args[1]);
	cd = chdir(home);
	if (cd < 0)
		no_file(var, var->prs->cmd, home, ": No such file or directory\n");
	else
		ch_pwd(var);
}
