/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_readline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:32:09 by msaouab           #+#    #+#             */
/*   Updated: 2022/03/28 14:43:37 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	assign_list(t_var *var, t_his **list, t_his *his)
{
	t_his	*curr;

	if (!(var->head_his))
	{
		var->head_his = his;
		*list = his;
	}
	else
	{
		curr = var->head_his;
		while (curr->next)
			curr = curr->next;
		his->prev = curr;
		curr->next = his;
		*list = curr->next;
	}
}

void	err_termios(char *err)
{
	ft_putstr_fd(err, 2);
	exit(-1);
}

void	termios_config(struct termios *old_attr)
{
	struct termios	new_attr;
	char			*term_type;
	int				ret;

	term_type = getenv("TERM");
	if (term_type == NULL)
		err_termios("\r\033[0KTERM must be set (see 'env').\n");
	ret = tgetent(NULL, term_type);
	if (ret < 0)
		err_termios("\r\033[0KCould not access to the termcap database..\n");
	if (ret == 0)
		err_termios("\r\033[0KIs not defined in termcap database.\n");
	if (tcgetattr(STDIN_FILENO, old_attr) < 0)
		err_termios("Error tcgetattr\n");
	new_attr = *old_attr;
	new_attr.c_lflag &= ~(ECHO | ICANON | ISIG);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &new_attr) < 0)
		err_termios("\r\033[0KError tcsetattr.\n");
}

t_his	*create_node_hist(void)
{
	t_his	*his;

	his = NULL;
	his = (t_his *)malloc(sizeof(t_his));
	his->next = NULL;
	his->prev = NULL;
	his->cursor = 0;
	his->input = NULL;
	return (his);
}
