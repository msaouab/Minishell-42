# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 12:54:06 by msaouab           #+#    #+#              #
#    Updated: 2022/04/17 22:18:17 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/libft.a

SRC =	./parsing/parser.c\
	  	./parsing/check_errors.c\
	  	./parsing/check_flags.c\
	  	./parsing/ft_error.c\
	  	./parsing/get_env.c\
	  	./parsing/create_lists_prs.c\
	  	./parsing/get_dollars.c\
	  	./parsing/get_cmd_arg.c\
	  	./parsing/get_files.c\
	  	./parsing/outils.c\
		./parsing/check_flgs_sdr.c\
		./parsing/hundel_error.c\
		./parsing/signal_handeler.c\
		./parsing/get_about_dollar.c\
		./parsing/ft_frees.c\
		./parsing/linked_list.c\
		./execution/execution.c\
	  	./execution/builtin.c\
		./execution/ft_echo.c\
		./execution/ft_pwd.c\
		./execution/ft_env.c\
		./execution/ft_cd.c\
		./execution/ft_exit.c\
		./execution/ft_export.c\
		./execution/ft_unset.c\
		./execution/error.c\
		./execution/open_file.c\
	  	./execution/free.c\
	  	./execution/pipe.c\
	  	# ./execution/echo_builtin.c \
	  	# ./execution/error_file.c\
		# ./execution/export_builtin.c\
		# ./execution/message_errors.c\
		# ./execution/pipe_execution.c\
		# ./execution/utils.c\
		# ./execution/beta_export.c\

OBJ = $(SRC:.c=.o)

magenta = `tput setaf 5`

white = `tput setaf 7`

bold = $(shell tput bold)

ED = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) -lreadline $(LIB) -lncurses -o $(NAME)
	@echo "$(white)${bold}LIBRARY CREATION${ED}"
	@echo "$(white)${bold}... DONE ...${ED}"

%.o : %.c
	@echo "${bold}${white}COMPILING SRC...[OK]${ED}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "${bold}${magenta}REMOVE LIBRARY...[OK]${ED}"
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@echo "${bold}${magenta}REMOVE EXECUTION...[OK]${ED}"
	@make -C libft fclean

re: fclean all
