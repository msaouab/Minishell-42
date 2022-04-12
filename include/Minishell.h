/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:09:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/04/11 23:03:35 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define	MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include <dirent.h>
# include <curses.h>
# include <term.h>
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
	struct s_his	*prev;}				t_his;

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
	pid_t		*tab_pipe;
	pid_t		pid;
	t_parser	*prs;
	t_parser	*parser;
	t_parser	*prsTail;
	t_env		*head_env;
	t_his		*head_his;
}				t_var;

t_var	*g_var;

int		isprint_car(int p);
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
void	check_semicolomn(int i, t_var *var);
void	check_pipe(int i, t_var *var);
void	conv_neg_space(int i, t_var *var);
void	hundel_error(int err, t_var *var);
void	get_env(char **envp, t_var *var);
void	ft_lstadd_back(t_env **alst, t_env *news);
t_env	*create_node(char **key_value);
char	**split_env(char *line);
t_var	*get_struc_var(t_var *ptr);
void	free_list_cmd(t_parser *prs, t_var *var);
void	free_list_files(t_parser *prs);
void	add_prs_tonode(t_var *var, t_parser *node);
void	add_files_tonode(t_files *fil, t_var *var);
void	search_file(t_var *var, int *j);
void	search_cmd_args(t_var *var, int *j);
void	clear_line(t_var *var, char **line);
int		set_index(char *str);
char	*get_env_value(t_var *var);
void	read_line(t_var *var);
void	ft_free_args(char **args);
int		ft_strcmp(const char *s1, const char *s2);
void	assign_list(t_var *var, t_his **ls_actual, t_his *his);
t_his	*create_node_hist(void);
void	termios_config(struct termios *old_attr);
void	delete_node(t_var *var);
void	func_cntrl_c(t_his *his, t_var *var, t_his **ls_actual);
void	func_cntrl_d(t_var *var, t_his **ls_actual);
void	func_press_del(t_his **ls_actual);
void	func_press_up(t_his **ls_actual);
void	func_press_down(t_his **ls_actual);
void	func_cont_rdl(int rp, t_var *var, t_his *his, t_his **list);
int		hundel_sq_dq_sm(t_var *var, int i);
int		hundel_pip_sp(t_var *var, int i);
void	off_flags_covneg(t_var *var, int *i);
int		hund_last_sc(int i, t_var *var);
void	new_str(char **str, int index);
void	del_sq_dq(char **line, int *i, t_var *var);
char	define_type_red(char **line, int *i, t_var *var);
int		check_empty_dollar(t_var *var, char **line, int *i);
void	check_dollar_first(t_var *var, char **line, int *i);
void	ft_free(t_var *var);
char	*get_home(t_var *var);
int		get_oldpwd(t_var *var);
char	*check_home(t_var *var);
void	export_env(t_var *var);
void	export_var(t_var *var, int *j);
int		echo_option(char *str, int *check);
int		ft_listsize(t_env *lst);
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
int		builtin(t_var *var);
int		ft_sign(char c);
int		ft_isdig(char *s);
char	**envp(t_var *var);
int		ft_listsize_prs(t_parser *prs);
int		ft_strcmp(const char *s1, const char *s2);
void	execute_pipe(t_var *var, char **env);
void	sys_execution_pipe(t_var *var, char **env);
void	ft_putstr_error(char *str1, char *str2, char *str3);
void	chpwd_bis(t_env *pwd, t_env *oldpwd, char *path);
char	*new_pwd(t_var *var, t_env *pwd, char *path);
int		existing_value_bis(t_var *var, char *key, char *value, int equal);
int		check_args(t_var *var, char *current);
char	**sort_key_value(t_var *var, char **key_value);
int		addvar_export(t_var *var, char	**key_value, int i);
int		existing_value(t_var *var, char *key, char *value, int equal);
int		fopen_read(t_var *var, t_files *files);
void	error_red_app(t_var *var, t_files *files);
int		redir_append(t_var *var, t_files *files);
char	*join_command(t_var *var);
void	open_file(t_var *var);
char	*find_path(t_var *var, char **path);
char	*join_path(t_var *var);
void	ft_execve(char *tmp, t_var *var, char **env);
void	error_command(char *str, t_var *var);
void	error_open_file(t_var *var, t_files *files);
void	replace_pwd(t_env *pwd, t_env *oldpwd, char *path);
void	pipe_exec(t_var *var, int *pipefds, int pipenumber, char **env);
void	no_file(char *cmd, char *file);
char	**envp_continue(t_env *current, char **key_value, int *i);
void	pipe_exec(t_var *var, int *pipefds, int pipenumber, char **env);
void	pipe_exec_bis(t_parser *prs, int *pipefds, int j);
void	signal_handler_c(int signo);
void	signal_handler_quit(int signo);
void	init_env(t_var *var, char **env);


void	ch_pwd(t_var *var, char *home);

#endif

