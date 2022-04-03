/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:49 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/01 22:14:59 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execution(t_var *var, char **env)
{
	(void)env;
	if (ft_listsize_prs(var->prs) == 1)
	{
		// if (ft_listsize_file(var->prs->file_head) > 0)
		// 	open_file(var);
		if (!var->error)
		{
			builtin(var);
			// if (builtin(var) < 0 && !var->error)
				// sys_execution(var, env);
		}
	}
	// else if (ft_listsize_prs(var->prs) > 1)
	// 	execute_pipe(var, env);
	dup2(var->old_in, STDIN_FILENO);
	dup2(var->old_out, STDOUT_FILENO);
}