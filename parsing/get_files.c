/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:00 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:25 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	remove_file(int *i, int org, int *j, t_var *var)
{
	char	*str1;
	char	*str2;
	int		len;

	len = ft_strlen(var->split_pip[*j]);
	str1 = ft_substr(var->split_pip[*j], *i, len);
	var->split_pip[*j][org] = '\0';
	str2 = var->split_pip[*j];
	var->split_pip[*j] = ft_strjoin(str2, str1);
	free(str1);
	free(str2);
	*i = org - 1;
}

char	*get_filename(int *i, int *j, t_var *var)
{
	int		org;
	int		start;
	int		end;
	char	*tmp;

	org = *i;
	start = 0;
	end = 0;
	*i += var->step;
	while (var->split_pip[*j][*i] == ' ')
	{
		(*i)++;
		start++;
	}
	while (var->split_pip[*j][*i] != ' ' && var->split_pip[*j][*i] &&
			var->split_pip[*j][*i] != '>' && var->split_pip[*j][*i] != '<')
	{
		(*i)++;
		end++;
	}
	tmp = ft_substr(var->split_pip[*j], org + var->step + start, end);
	remove_file(i, org, j, var);
	(*i)--;
	return (tmp);
}

void	check_nodefile(t_var *var, t_files **fil)
{
	if ((*fil)->type != '1')
	{
		add_files_tonode(*fil, var);
		*fil = (t_files *)malloc(sizeof(t_files));
		(*fil)->next = NULL;
	}
}

void	split_typeredir(t_var *var, t_files **fil, int *i, int *j)
{
	if (var->split_pip[*j][*i] == '>')
	{
		(*fil)->type = RIGHT_R;
		var->step = 1;
		(*fil)->file_name = get_filename(i, j, var);
	}
	else if (var->split_pip[*j][*i] == '<')
	{
		(*fil)->type = LEFT_R;
		var->step = 1;
		(*fil)->file_name = get_filename(i, j, var);
	}
}

void	search_file(t_var *var, int *j)
{
	t_files	*fil;
	int		i;

	i = -1;
	fil = (t_files *)malloc(sizeof(t_files));
	fil->next = NULL;
	while (var->split_pip[*j][++i])
	{
		fil->type = '1';
		if (var->split_pip[*j][i] == '>' && var->split_pip[*j][i + 1] == '>')
		{
			fil->type = APPEND;
			var->step = 2;
			fil->file_name = get_filename(&i, j, var);
		}
		else
			split_typeredir(var, &fil, &i, j);
		check_nodefile(var, &fil);
	}
	fil->type = '1';
	if (fil->type == '1')
		free(fil);
}
