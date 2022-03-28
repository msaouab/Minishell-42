/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists_prs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:26 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:42:51 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_files_tonode(t_files *fil, t_var *var)
{
	t_files	*curr;

	curr = var->prsTail->file_head;
	if (!curr)
		var->prsTail->file_head = fil;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = fil;
	}
}

void	add_prs_tonode(t_var *var, t_parser *node)
{
	if (!var->prs)
	{
		var->prs = node;
		var->prsTail = node;
	}
	else
	{
		var->prsTail->next_prs = node;
		var->prsTail = node;
	}
}
