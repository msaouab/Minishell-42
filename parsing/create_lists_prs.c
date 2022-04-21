/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists_prs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:26 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 14:45:19 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/minishell.h"

void	add_files_tonode(t_files *fil, t_var *var)
{
	t_files	*curr;

	curr = var->prstail->file_head;
	if (!curr)
		var->prstail->file_head = fil;
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
		var->prstail = node;
	}
	else
	{
		var->prstail->next_prs = node;
		var->prstail = node;
	}
}
