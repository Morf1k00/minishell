# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:11:32 by rkrechun          #+#    #+#              #
#    Updated: 2024/05/10 16:00:53 by debizhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minihell
CC		= gcc -g -fsanitize=address
FLAGS	= -Wall -Wextra -Werror
LIBS	= -lreadline
RM		= rm -rf
NAME	= minishell
HEADER	= minishell.h

MPATH	= minishell.c  ft_split.c ft_strjoin.c env_init.c split_arg.c word_cpy.c redirection.c #line_read.c
OBJ_M	= $(MPATH:.c=.o)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_M)
	@$(CC) $(OBJ_M) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ_M)

fclean: clean
	@$(RM) $(NAME)
	
	
.PHONY: all clean fclean