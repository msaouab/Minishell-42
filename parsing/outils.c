/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:21 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:44:43 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isalphnum(int c)
{
	if (c >= '0' && c <= '9')
		return (2);
	if (c == '_')
		return (1);
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	set_index(char *str)
{
	int	j;

	j = -1;
	while (str[++j] != '\0')
	{
		if (ft_isalphnum(str[j]))
		{
			if (ft_isalphnum(str[j]) == 2 && str[j - 1] == '$')
			{
				j++;
				break ;
			}
		}
		if (!ft_isalphnum(str[j]))
			break ;
	}
	return (j);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (str1[index] != '\0' && str2[index] != '\0')
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
	}
	if (((str1[index] != '\0' && str2[index] == '\0')
			|| (str1[index] == '\0' && str2[index] != '\0')))
		return (str1[index] - str2[index]);
	return (0);
}

char	*get_env_value(t_var *var)
{
	t_env	*curr;

	if (var->head_env)
	{
		curr = var->head_env;
		while (curr && ft_strcmp(curr->key, var->str_key) != 0)
			curr = curr->next;
		if (curr)
		{
			if (curr->value)
				return (ft_strdup(curr->value));
			else
				return (ft_strdup(""));
		}
		if (!ft_strcmp(var->str_key, "0"))
			return (ft_strdup(NAME_OUTPUT));
	}
	return (ft_strdup(""));
}

int	hund_last_sc(int i, t_var *var)
{
	if (var->redir_right || var->redir_left || var->redir_double
		|| var->semi_colomn || var->pipe)
		hundel_error(TOKEN_SC, var);
	while (var->line[++i])
		if (isprint_car(var->line[i]) || var->line[i] != '"')
			return (1);
	return (0);
}
