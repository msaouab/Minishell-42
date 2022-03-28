# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knabouss <knabouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 14:30:35 by mbelaman          #+#    #+#              #
#    Updated: 2021/04/12 17:30:33 by knabouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c isprint_car.c

OBJ_SRC = $(SRC:.c=.o)

# BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c

# BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@ar rcs $(NAME) $^

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

# bonus: $(OBJ_SRC) $(BONUS_OBJ)
# 	@ar rcs $(NAME) $^

clean:
	@rm -rf $(OBJ_SRC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
