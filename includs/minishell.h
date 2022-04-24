/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:09:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/24 13:56:49 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include "../libft/libft.h"
# include <dirent.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# define NAME_OUTPUT "minishell"
# define KEY_U 0x415b1b
# define KEY_DW 0x425b1b
# define KEY_EN 10
# define KEY_DEL 127
# define CTRL_L 0xc
# define CTRL_D 4
# define CTRL_C 0x3
# define TOKEN_RR 1
# define TOKEN_RL 2
# define TOKEN_DR 3
# define TOKEN_SC 4
# define TOKEN_DSC 7
# define TOKEN_PIP 5
# define NEW_LINE 6
# define TOKEN_DPIP 8
# define TOKEN_DOLLAR -90
# define APPEND 'a'
# define RIGHT_R '>'
# define LEFT_R '<'

typedef struct s_his
{
	char			*input;
	int				cursor;
	struct s_his	*next;
	struct s_his	*prev;
}				t_his;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				print;
	struct s_env	*next;
}				t_env;

typedef struct s_files
{
	char			type;
	char			*file_name;
	struct s_files	*next;
}				t_files;

typedef struct s_parser
{
	char			*cmd;
	char			**args;
	t_files			*file_head;
	struct s_parser	*next_prs;
}				t_parser;

typedef struct s_var
{
	int			single_q;
	int			double_q;
	int			semi_colomn;
	int			pipe;
	int			redir_left;
	int			redir_right;
	int			redir_double;
	int			back_sl;
	int			error;
	char		type;
	char		*line;
	char		**split_sc;
	char		**split_pip;
	char		*str_key;
	char		*str_val;
	int			i_d;
	int			step;
	char		*home;
	int			exit;
	int			old_out;
	int			old_in;
	int			fd[2];
	int			fdp[2];
	char		**key_value;
	int			status;
	int			plus;
	char		*tmp;
	int			hanlder_c;
	pid_t		*tab_pipe;
	pid_t		pid;
	t_parser	*prs;
	t_parser	*parser;
	t_parser	*prstail;
	t_env		*head_env;
	t_his		*head_his;
}				t_var;

t_var	*g_var;

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
void	syntax_error(t_var *var, int i);
int		hund_last_sc(int i, t_var *var);
void	check_single_q(t_var *var);
void	check_double_q(t_var *var);
void	check_redir_r(int i, t_var *var);
void	check_redir_l(int i, t_var *var);
void	check_redir_d(int i, t_var *var);
void	check_semicolomn(int i, t_var *vcar);
void	check_pipe(int i, t_var *var);
void	conv_neg_space(int i, t_var *var);
void	hundel_error(int err, t_var *var);
void	ft_lstadd_back(t_env **alst, t_env *news);
t_env	*create_node(char **key_value);
void	free_list_cmd(t_parser *prs, t_var *var);
void	add_prs_tonode(t_var *var, t_parser *node);
void	add_files_tonode(t_files *fil, t_var *var);
void	search_file(t_var *var, int *j);
void	search_cmd_args(t_var *var, int *j);
void	clear_line(t_var *var, char **line);
int		set_index(char *str);
char	*get_env_value(t_var *var);
void	ft_free_args(char **args);
int		ft_strcmp(const char *s1, const char *s2);
int		hundel_sq_dq_sm(t_var *var, int i);
int		hundel_pip_sp(t_var *var, int i);
void	off_flags_covneg(t_var *var, int *i);
void	new_str(char **str, int index);
void	del_sq_dq(char **line, int *i, t_var *var);
char	define_type_red(char **line, int *i, t_var *var);
int		check_empty_dollar(t_var *var, char **line, int *i);
void	check_dollar_first(t_var *var, char **line, int *i);
void	ft_free(t_var *var);
int		ft_listsize_file(t_files *files);
char	*find_value(char *find, t_var *var);
void	ft_pwd(t_var *var);
void	ft_env(t_var *var);
void	ft_cd(t_var *var);
void	ft_unset(t_var *var);
void	ft_exit(t_var *var);
void	ft_echo(t_var *var);
void	ft_export(t_var *var);
void	execution(t_var *var, char **env);
void	sys_execution(t_var *var, char **env);
int		builtin(t_var *var, int pipe);
int		ft_listsize_prs(t_parser *prs);
char	*join_command(t_var *var);
void	open_file(t_var *var);
void	signal_handler_c(int signo);
void	signal_handler_quit(int signo);
void	init_env(t_var *var, char **env);
void	ch_pwd(t_var *var);
void	ft_write(char *cmd);
void	no_file(t_var *var, char *cmd, char *arg, char *msg);
void	ft_error(char *file);
void	ft_exit(t_var *var);
void	ft_assign(char **dst, char *src, char *to_free);
void	pipeline(t_var *var, char **env);
void	ft_multi_args(char *bash);
void	ft_free_doble(char **str, char *s);

#endif
