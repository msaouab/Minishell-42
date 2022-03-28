/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:52 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:13 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	func_val_dollar(t_var *var, char **line, int *i)
{
	var->i_d = set_index((*line) + *i + 1);
	var->str_key = ft_substr((*line) + *i + 1, 0, var->i_d);
	var->str_val = get_env_value(var);
}

void	func_change_line(t_var *var, char **line, int *i)
{
	var->str_key = ft_strjoin(var->str_val, (*line) + *i + 1 + var->i_d);
	free(var->str_val);
	(*line)[*i] = '\0';
	var->str_val = ft_strjoin((*line), var->str_key);
	free(*line);
	free(var->str_key);
	(*line) = var->str_val;
}

void	replace_dollar(t_var *var, char **line, int *i)
{
	var->i_d = 1;
	var->type = define_type_red(line, i, var);
	if ((*line)[*i] == '$' && var->single_q == 0)
	{
		if ((*line)[*i + 1] == '?')
			var->str_val = ft_itoa(var->status);
		else
		{
			func_val_dollar(var, line, i);
			if (check_empty_dollar(var, line, i))
				return ;
		}
		if (var->i_d != 0)
			func_change_line(var, line, i);
		else
		{
			if (var->str_val)
				free(var->str_val);
		}
	}
	check_dollar_first(var, line, i);
}

void	check_line(t_var *var, char **line, int *i)
{
	if (var->double_q == 1 && (*line)[*i] == '\\' && ((*line)[*i + 1] == '$'
		|| (*line)[*i + 1] == '\"' || (*line)[*i + 1] == '\\'
		|| (*line)[*i + 1] == '`'))
		new_str(line, *i);
	if ((var->double_q || var->single_q) && (*line)[*i] > 0)
		(*line)[*i] = -(*line)[*i];
	if (var->double_q == 0 && var->single_q == 0 && (*line)[*i] == '\\'
		&& (*line)[*i + 1] == '\\')
	{
		new_str(line, *i);
		(*line)[*i] = -(*line)[*i];
	}
	if (var->double_q == 0 && var->single_q == 0 && (*line)[*i] == '\\')
	{
		if ((*line)[*i + 1] == '\0')
		{
			hundel_error(NEW_LINE, var);
			return ;
		}
		new_str(line, *i);
		if ((*line)[*i] == '\'' || (*line)[*i] == '\"')
			(*line)[*i] = -(*line)[*i];
	}
}

void	clear_line(t_var *var, char **line)
{
	int	i;

	var->single_q = 0;
	var->double_q = 0;
	i = -1;
	while ((*line)[++i] != '\0')
	{
		del_sq_dq(line, &i, var);
		replace_dollar(var, line, &i);
		del_sq_dq(line, &i, var);
		check_line(var, line, &i);
		if ((*line)[i - 1] == '$' && (*line)[i] == TOKEN_DOLLAR)
			continue ;
		if ((*line)[i - 1] == '$' && (*line)[i] != '/' && (*line)[i] != '$')
		{
			i = i - 1;
			replace_dollar(var, line, &i);
		}
	}
}
