/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:46:36 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 01:06:11 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/minishell.h"

int	builtin(t_var *var, int pipe)
{
	if (!(ft_strncmp("cd", *(var->prs->args), 3)) && !var->error)
		ft_cd(var);
	else if (!(ft_strncmp("pwd", *(var->prs->args), 4)) && !var->error)
		ft_pwd(var);
	else if (!(ft_strncmp("env", *(var->prs->args), 4)) && !var->error)
		ft_env(var);
	else if (!(ft_strncmp("exit", *(var->prs->args), 5)) && !var->error)
		ft_exit(var);
	else if (!(ft_strncmp("echo", *(var->prs->args), 5)) && !var->error)
		ft_echo(var);
	else if (!(ft_strncmp("export", *(var->prs->args), 7)) && !var->error)
		ft_export(var);
	else if (!(ft_strncmp("unset", *(var->prs->args), 6)) && !var->error)
		ft_unset(var);
	else
		return (-1);
	if (pipe == 1)
		exit (0);
	return (0);
}
