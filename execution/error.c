/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:38:00 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/19 12:30:55 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error(char *file)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	ft_write(char *cmd)
{
	write(2, "minishell: command not found: ", 30);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

void	no_file(t_var *var, char *cmd, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(msg, 2);
	var->status = 1;
}

void	ft_multi_args(char *bash)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(bash, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit(0);
}
