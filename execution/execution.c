/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:49 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/18 17:28:14 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_path(t_var *var)
{
	if (access(var->prs->cmd, X_OK) == 0)
		return (1);
	return (0);
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

	if (check_path(var) == 1)
		return (var->prs->cmd);
	else
	{
		path = get_path(var);
		cmd = var->prs->cmd;
		cmd = ft_strjoin("/", cmd);
		i = -1;
		while (path[++i])
		{
			ft_assign(&path[i], ft_strjoin(path[i], cmd), path[i]);
			if (access(path[i], X_OK) == 0)
			{
				cmd = path[i];
				return (path[i]);
			}
		}
	}
	if (path[i] == NULL)
		ft_write(var->prs->cmd);
	return (NULL);
}

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
		execve(path, var->prs->args, env);
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
	else if (ft_listsize_prs(var->prs) > 1)
		pipeline(var, env);
	dup2(var->old_in, STDIN_FILENO);
	dup2(var->old_out, STDOUT_FILENO);
}
