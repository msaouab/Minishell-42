/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:07:50 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/17 22:50:33 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pipeline(t_var *var, char **env)
{
	(void)env;
	int	n_pipe;
	int	i;

	n_pipe = ft_listsize_prs(var->prs) - 1;
	i = 0;
	pipe(var->fd);
	while (i < n_pipe)
	{
		var->pid = fork();
		if (var->pid < 0)
			perror("pid");
		if (var->pid == 0)
		{
			dup2(var->)
		}
	}
}