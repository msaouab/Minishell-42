/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:54:07 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 12:29:02 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	old_pwd(t_env *oldpwd, char *tmp)
{
	while (oldpwd)
	{
		if (ft_strncmp(oldpwd->key, "OLDPWD", 6) == 0)
		{
			free (oldpwd->value);
			oldpwd->value = ft_strdup(tmp);
		}
		oldpwd = oldpwd->next;
	}
}

void	ch_pwd(t_var *var)
{
	t_env	*current;
	t_env	*oldpwd;
	char	*tmp;
	char	cwd[PATH_MAX];

	current = var->head_env;
	oldpwd = var->head_env;
	while (current)
	{
		if (ft_strncmp(current->key, "PWD", 4) == 0)
		{
			tmp = current->value;
			free(current->value);
			current->value = ft_strdup(getcwd(cwd, sizeof(cwd)));
		}
		current = current->next;
	}
	old_pwd(oldpwd, tmp);
}

void	ft_pwd(t_var *var)
{
	t_env	*current;
	char	pwd[PATH_MAX];

	current = var->head_env;
	while (current && ft_strncmp("PWD", current->key, 3))
		current = current->next;
	ft_putstr_fd(getcwd(pwd, sizeof(pwd)), 1);
	ft_putstr_fd("\n", 1);
}
