/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:07:50 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/18 17:23:22 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	duplicate(t_parser *prs, int *pipefds, int i)
{
	if (prs->next_prs)
		dup2(pipefds[i + 1], STDOUT_FILENO);
	if (i != 0)
		dup2(pipefds[i - 2], STDIN_FILENO);
}

// void	ft_execve(char *tmp, t_var *var, char **env)
// {
// 	if (execve(tmp, var->prs->args, env) < 0)
// 	{
// 		if (!(ft_strcmp(tmp, "")))
// 		{
// 			no_file(var, var->prs->cmd, "", ": No such file or directory\n");
// 			free(tmp);
// 		}
// 		// else if (tmp != NULL)
// 			// error_command(*var->prs->args, var);
// 		exit(127);
// 	}
// }

void	sys_execution_pipe(t_var *var, char **env)
{
	var->tmp = join_command(var);
	if (!var->tmp)
		return ;
	execve(var->tmp, var->prs->args, env);
	// ft_execve(var->tmp, var, env);
}

void	pipeline(t_var *var, char **env)
{
	(void)env;
	int	n_pipe;
	int	*pipefds;
	int	i;
	int	j;

	n_pipe = ft_listsize_prs(var->prs) - 1;
	pipefds = malloc(sizeof(int) * n_pipe);
	var->tab_pipe = malloc(sizeof(pid_t) * n_pipe);
	i = -1;
	while (++i < n_pipe)
		pipe(pipefds + i * 2);
	i = 0;
	var->parser = var->prs;
	while (var->prs)
	{
		j = -1;
		var->pid = fork();
		if (var->pid < 0)
			perror("fork");
		if (var->pid == 0)
		{
			duplicate(var->prs, pipefds, i);
			if (ft_listsize_file(var->prs->file_head) > 0)
				open_file(var);
			while (++j < 2 * n_pipe)
				close(pipefds[j]);
			if (builtin(var) < 0 && !var->error)
				sys_execution_pipe(var, env);
				// sys_execution(var, env);
		}
		var->prs = var->prs->next_prs;
		var->tab_pipe[j / 2] = var->pid;
		i += 2;
	}
	var->prs = var->parser;
	j = -1;
	while (++j < 2 * n_pipe)
		close(pipefds[j]);
	i = -1;
	while (++i < n_pipe + 1)
		waitpid(var->tab_pipe[i], &var->status, 0);
}