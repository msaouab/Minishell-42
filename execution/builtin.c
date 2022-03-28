/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:46:36 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:47:14 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



int	builtin(t_var *var)
{
	if (!(ft_strncmp("cd", *(var->prs->args), 3)) && !var->error)
		builtin_cd(var);
	else if (!(ft_strncmp("pwd", *(var->prs->args), 4)) && !var->error)
		builtin_pwd(var);
	else if (!(ft_strncmp("env", *(var->prs->args), 4)) && !var->error)
		builtin_env(var);
	else if (!(ft_strncmp("unset", *(var->prs->args), 6)) && !var->error)
		builtin_unset(var);
	else if (!(ft_strncmp("exit", *(var->prs->args), 5)) && !var->error)
		builtin_exit(var);
	else if (!(ft_strncmp("export", *(var->prs->args), 7)) && !var->error)
		builtin_export(var);
	else if (!(ft_strncmp("echo", *(var->prs->args), 5)) && !var->error)
		builtin_echo(var);
	else
		return (-1);
	return (0);
}