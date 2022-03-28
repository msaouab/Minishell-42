/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundel_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:05 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:28 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	off_flags_covneg(t_var *var, int *i)
{
	if (var->redir_right || var->redir_left || var->redir_double
		|| var->semi_colomn)
	{
		var->redir_right = 0;
		var->redir_left = 0;
		var->redir_double = 0;
		var->semi_colomn = 0;
	}
	var->line[*i + 1] = -var->line[*i + 1];
	(*i)++;
}

void	check_carac(char c, t_var *var)
{
	if ((var->semi_colomn || var->redir_left || var->redir_right
			|| var->redir_double || var->pipe) && isprint_car(c))
	{
		var->semi_colomn = 0;
		var->redir_left = 0;
		var->redir_right = 0;
		var->redir_double = 0;
		var->pipe = 0;
	}
}

void	hundel_semicolomne(t_var *var, int i)
{
	if (var->line[0] == ';' && var->line[i + 1] != ';')
		hundel_error(TOKEN_SC, var);
	else if (var->line[i + 1] == ';' && var->single_q && var->double_q)
		hundel_error(TOKEN_DSC, var);
	else if (var->line[i + 1] == ';' && !var->single_q && !var->double_q)
		hundel_error(TOKEN_DSC, var);
	else if (hund_last_sc(i, var))
		check_semicolomn(i, var);
}

int	hundel_pip_sp(t_var *var, int i)
{
	if (var->line[i] == '|')
	{
		check_pipe(i, var);
		return (1);
	}
	else if (var->line[i] == ' ')
	{
		conv_neg_space(i, var);
		return (1);
	}
	else
	{
		check_carac(var->line[i], var);
		return (1);
	}
	return (0);
}

int	hundel_sq_dq_sm(t_var *var, int i)
{
	if (var->line[i] == '\'')
	{
		check_single_q(var);
		return (1);
	}
	else if (var->line[i] == '"')
	{
		check_double_q(var);
		return (1);
	}
	else if (var->line[i] == ';')
	{
		hundel_semicolomne(var, i);
		return (1);
	}
	return (0);
}
