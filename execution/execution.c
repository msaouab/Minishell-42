/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:49 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/13 15:01:39 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_assign(char **dst, char *src, char *to_free)
{
	*dst = src;
	free(to_free);
}

char	**get_path(t_var *var)
{
	t_env	*current;
	char	**path;

	current = var->head_env;
	while (current)
	{
		if (ft_strncmp("PATH", current->key, 4) == 0)
		{
			path = ft_split(current->value, ':');
			return (path);
		}
		current = current->next;
	}
	return (NULL);
}

char	*join_command(t_var *var)
{
	char	**path;
	char	*cmd;
	int		i;

	i = 0;
	path = get_path(var);
	cmd = var->prs->cmd;
	cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		ft_assign(&path[i], ft_strjoin(path[i], cmd), path[i]);
		if (access(path[i], X_OK) == 0)
		{
			cmd = path[i];
			// ft_free_args(path);
			return (path[i]);
		}
		i++;
	}
	if (path[i] == NULL)
		ft_write(var->prs->cmd);
	return (NULL);
}

// void	ft_execve(t_var *var, char **env, char *path)
// {
	
// }

void	sys_execution(t_var *var, char **env)
{
	t_files	*file;
	char	*path;

	file = var->prs->file_head;
	path = join_command(var);
	var->pid = fork();
	if (var->pid == -1)
		strerror(var->pid);
	if (var->pid == 0)
	{
		execve(path, var->prs->args, env);
	}
	waitpid(var->pid, NULL, 0);
}

void	execution(t_var *var, char **env)
{
	if (ft_listsize_prs(var->prs) == 1)
	{
		if (ft_listsize_file(var->prs->file_head) > 0)
			open_file(var);
		if (!var->error)
		{
			if (builtin(var) < 0 && !var->error)
				sys_execution(var, env);
		}
	}
	// else if (ft_listsize_prs(var->prs) > 1)
	// 	execute_pipe(var, env);
	dup2(var->old_in, STDIN_FILENO);
	dup2(var->old_out, STDOUT_FILENO);
}
