/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:02 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:42:40 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_allflgs(t_var *var)
{
	if (var->semi_colomn)
		hundel_error(TOKEN_DSC, var);
	else if (var->semi_colomn || var->redir_left || var->redir_right
		|| var->redir_double || var->pipe || var->double_q || var->single_q)
		hundel_error(NEW_LINE, var);
}

int	hundel_backsl_two(t_var *var, int *i)
{
	if (!var->double_q && var->line[*i] == '\\'
		&& (var->line[*i + 1] == ';' || var->line[*i + 1] == '|'
			|| var->line[*i + 1] == ' ' || var->line[*i + 1] == '>'
			|| var->line[*i + 1] == '<'))
	{
		off_flags_covneg(var, i);
		return (1);
	}
	else if (var->double_q && var->line[*i] == '\\'
		&& (var->line[*i + 1] == ';'))
	{
		var->line[*i + 1] = -var->line[*i + 1];
		return (1);
	}
	else if (var->line[*i] == '\\' && !var->single_q)
	{
		(*i)++;
		return (1);
	}
	return (0);
}

int	hundel_backsl_one(t_var *var, int *i)
{
	if (!var->single_q && var->line[*i] == '\\' && var->line[*i + 1] == '`')
	{
		(*i)++;
		return (1);
	}
	else if (!var->single_q && var->line[*i] == '`')
	{
		hundel_error(NEW_LINE, var);
		return (1);
	}
	else if (var->line[*i] == '\\' && !var->line[*i + 1])
	{
		hundel_error(NEW_LINE, var);
		return (1);
	}
	else if (hundel_backsl_two(var, i))
		return (1);
	return (0);
}

int	hundel_all_redir(t_var *var, int *i)
{
	if (var->line[*i] == '>' && var->line[*i + 1] == '>')
	{
		check_redir_d(*i, var);
		*i += 1;
		return (1);
	}
	else if (var->line[*i] == '>')
	{
		check_redir_r(*i, var);
		return (1);
	}
	else if (var->line[*i] == '<')
	{
		check_redir_l(*i, var);
		return (1);
	}
	return (0);
}

void	syntax_error(t_var *var, int i)
{
	while (var->line[++i])
	{
		if (hundel_backsl_one(var, &i))
		{
			if (var->error != 0)
				return ;
		}
		else if (hundel_sq_dq_sm(var, i))
		{
			if (var->error != 0)
				return ;
		}
		else if (hundel_all_redir(var, &i))
		{
			if (var->error != 0)
				return ;
		}
		else if (hundel_pip_sp(var, i))
		{
			if (var->error != 0)
				return ;
		}
	}
	check_allflgs(var);
}
