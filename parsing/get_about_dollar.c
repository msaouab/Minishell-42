/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_about_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:43 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:05 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_dollar_first(t_var *var, char **line, int *i)
{
	if ((*line)[*i] == '$' && ((*line)[*i + 1] == '"' || (*line)[*i + 1] == '\'')
		&& (var->double_q == 1 || var->single_q == 1))
		return ;
	if ((*line)[*i] == '$' && ((*line)[*i + 1] == '"' || (*line)[*i + 1] == '\'')
		&& (var->double_q == 0 || var->single_q == 0))
	{
		new_str(line, *i);
		del_sq_dq(line, i, var);
	}
}

void	new_str(char **str, int index)
{
	while ((*str)[index] != '\0')
	{
		(*str)[index] = (*str)[index + 1];
		index++;
	}
}

void	del_sq_dq(char **line, int *i, t_var *var)
{
	if (((*line)[0] == '"' && (*line)[1] == '"' && (*line)[2] == '\0')
		|| ((*line)[0] == '\'' && (*line)[1] == '\'' && (*line)[2] == '\0'))
		return ;
	if (((*line)[*i] == '\"' || (*line)[*i] == '\'')
		&& ((*line)[*i + 1] == '>' || (*line)[*i + 1] == '<'))
	{
		(*line)[*i] = ' ';
		if (var->double_q)
			var->double_q = !(var->double_q);
		else
			var->single_q = !(var->single_q);
	}
	if ((*line)[*i] == '\"' && var->single_q == 0)
	{
		new_str(line, *i);
		var->double_q = !(var->double_q);
		del_sq_dq(line, i, var);
	}
	if ((*line)[*i] == '\'' && var->double_q == 0)
	{
		new_str(line, *i);
		var->single_q = !(var->single_q);
		del_sq_dq(line, i, var);
	}
}

char	define_type_red(char **line, int *i, t_var *var)
{
	if ((*line)[*i] == '>' && (*line)[*i - 1] == '>')
		return (var->type = 'a');
	else if ((*line)[*i] == '>')
		return (var->type = '>');
	else if ((*line)[*i] == '<')
		return (var->type = '<');
	return (var->type);
}

int	check_empty_dollar(t_var *var, char **line, int *i)
{
	if (!ft_strcmp(var->str_val, "")
		&& (var->type == 'a' || var->type == '>' || var->type == '<'))
	{
		free(var->str_val);
		var->str_val = NULL;
		if (var->i_d != 0 && (*line)[*i - 1] != '$')
		{
			(*line)[*i] = TOKEN_DOLLAR;
			free(var->str_key);
			var->type = '1';
			return (1);
		}
	}
	var->type = '1';
	free(var->str_key);
	return (0);
}
