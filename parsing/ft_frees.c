/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:39 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 14:46:00 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/minishell.h"

void	ft_free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		free(args[i]);
		args[i] = NULL;
	}
	if (args)
		free(args);
	args = NULL;
}

void	free_files(t_parser *prs)
{
	t_files	*curr;
	t_files	*next_node;

	curr = prs->file_head;
	next_node = NULL;
	while (curr)
	{
		next_node = curr->next;
		if (curr->file_name)
			free(curr->file_name);
		free(curr);
		curr = next_node;
	}
	prs->file_head = NULL;
}

void	free_list(t_var *var)
{
	t_parser	*curr;

	curr = var->prs;
	while (curr)
	{
		var->prstail = curr->next_prs;
		if (curr->args)
			ft_free_args(curr->args);
		curr->args = NULL;
		if (curr->file_head)
			free_files(curr);
		free(curr);
		curr = var->prstail;
	}
	var->prs = NULL;
}

void	ft_free(t_var *var)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (var->split_pip)
	{
		while (var->split_pip[++i])
			free(var->split_pip[i]);
		if (var->split_pip)
			free(var->split_pip);
	}
	if (var->split_sc)
	{
		while (var->split_sc[++j])
			free(var->split_sc[j]);
		if (var->split_sc)
			free(var->split_sc);
	}
	if (var->line)
		free(var->line);
	free_list(var);
}
