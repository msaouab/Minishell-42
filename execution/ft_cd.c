/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:10:47 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/08 22:34:24 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	no_file(char *cmd, char *file)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": no such file or directory: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
}

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

	if (!(var->prs->args[1]) || (ft_strncmp(var->prs->args[1], "~", 1) == 0))
		home = get_home(var);
	else
		home = ft_strdup(var->prs->args[1]);
	// printf("%s\n", var->prs->args[1]);
	cd = chdir(home);
	if (cd < 0)
		no_file(var->prs->cmd, home);
	else
		ch_pwd(var, home);
}