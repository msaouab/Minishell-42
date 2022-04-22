/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handeler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:55:57 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/22 01:32:41 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/minishell.h"

void	signal_handler_c(int signo)
{
	t_var	var;
	if (signo == SIGINT)
    {
        rl_on_new_line();
        ft_putstr_fd("\n", 1);
        rl_replace_line("", 0);
        if (var.hanlder_c == 1)
			rl_redisplay();
    }
	g_var->status = 130;
}

void	signal_handler_quit(int signo)
{
	(void)signo;
	ft_putstr_fd("Quit: 3\n", 2);
	g_var->status = 131;
}
