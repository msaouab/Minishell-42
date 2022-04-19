/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:46:41 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/18 17:52:04 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_key(char *str)
{
	int	i;

	if (ft_isdigit(str[0]))
		return (0);
	else
	{
		i = -1;
		while (str[++i])
		{
			if (str[i] == '=')
				break ;
			if (ft_isalnum(str[i]) == 0)
				return (0);
		}
	}
	return (1);
}

void	printenv(t_var *var)
{
	t_env	*current;

	current = var->head_env;
	while (current)
	{
		if (current->key)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(current->key, 1);
			if (ft_strcmp(current->value, "") != 0)
			{
				ft_putstr_fd("=\"", 1);
				ft_putstr_fd(current->value, 1);
				ft_putstr_fd("\"", 1);
			}
			ft_putstr_fd("\n", 1);
		}
		current = current->next;
	}
}

void	addvar_to_export(t_var *var, char **key_value, int i)
{
	t_env	*current;
	int	j;

	j = 0;
	current = var->head_env;
	while (var->prs->args[i][j] != '=' && var->prs->args[i][j])
		j++;
	key_value[0] = ft_substr(var->prs->args[i], 0, j);
	if (var->prs->args[i][j] == '=')
		key_value[1] = ft_substr(var->prs->args[i], j + 1, \
		ft_strlen(var->prs->args[i]) - j);
	else
		key_value[1] = ft_strdup("");
	while (current)
	{
		if (ft_strncmp(current->key, key_value[0], ft_strlen(key_value[0])) == 0)
			break ;
		current = current->next;
	}
	if (current)
		current->value = key_value[1];
	else
	{
		current = create_node(key_value);
		ft_lstadd_back(&var->head_env, current);
	}
}

void	ft_export(t_var *var)
{
	char	**key_value;
	int		i;

	if (!var->prs->args[1])
		printenv(var);
	i = 0;
	while (var->prs->args[++i])
	{
		if (check_key(var->prs->args[i]) == 0)
		{
			no_file(var, var->prs->cmd, var->prs->args[i],\
			": not a valid identifier\n");
		}
		else
		{
			key_value = malloc(sizeof(char) * 3);
			key_value[2] = NULL;
			addvar_to_export(var, key_value, i);
		}
	}
}
