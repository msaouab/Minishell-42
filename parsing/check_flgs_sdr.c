/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flgs_sdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:31:19 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:42:47 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	off_redir(t_var *var)
{
	if (var->redir_left || var->redir_right || var->redir_double)
	{
		var->redir_left = 0;
		var->redir_right = 0;
		var->redir_double = 0;
	}
	else if (var->semi_colomn)
		var->semi_colomn = 0;
}

void	check_single_q(t_var *var)
{
	off_redir(var);
	if (var->single_q)
		var->single_q = 0;
	else if (!var->double_q && !var->single_q)
		var->single_q = 1;
	if (var->semi_colomn)
		var->semi_colomn = 0;
}

void	check_double_q(t_var *var)
{
	off_redir(var);
	if (var->double_q)
		var->double_q = 0;
	else if (!var->double_q && !var->single_q)
		var->double_q = 1;
}

void	check_redir_r(int i, t_var *var)
{
	if (var->redir_right || var->redir_left || var->redir_double)
		hundel_error(TOKEN_RR, var);
	else if (var->double_q || var->single_q)
		var->line[i] = -var->line[i];
	else if (!var->double_q && !var->single_q)
		var->redir_right = 1;
}

void	check_redir_l(int i, t_var *var)
{
	if (var->redir_left)
		hundel_error(NEW_LINE, var);
	else if (var->redir_right || var->redir_left || var->redir_double)
		hundel_error(TOKEN_RL, var);
	else if (var->double_q || var->single_q)
		var->line[i] = -var->line[i];
	else if (!var->double_q && !var->single_q)
		var->redir_left = 1;
}
