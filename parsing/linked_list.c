/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:54:07 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/01 20:54:17 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstadd_back(t_env **alst, t_env *new)
{
	t_env	*lst;

	lst = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

char	*find_value(char *find, t_var *var)
{
	t_env	*current;

	current = var->head_env;
	while (current)
	{
		if (!(ft_strncmp(current->key, find, \
		ft_strlen(find))) && current->print == 1)
			break ;
		current = current->next;
	}
	if (current && current->print)
		return (ft_strdup(current->value));
	return (ft_strdup(""));
}

int	ft_listsize(t_env *lst)
{
	int	cpt;

	cpt = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		cpt++;
		lst = lst->next;
	}
	return (cpt);
}

int	ft_listsize_file(t_files *files)
{
	int	cpt;

	cpt = 0;
	if (!files)
		return (0);
	while (files)
	{
		cpt++;
		files = files->next;
	}
	return (cpt);
}

int	ft_listsize_prs(t_parser *prs)
{
	int	cpt;

	cpt = 0;
	if (!prs)
		return (0);
	while (prs)
	{
		cpt++;
		prs = prs->next_prs;
	}
	return (cpt);
}
