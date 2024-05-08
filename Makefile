# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:11:32 by rkrechun          #+#    #+#              #
#    Updated: 2024/05/08 17:12:24 by debizhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc -g -fsanitize=address
FLAGS	= -Wall -Wextra -Werror
LIBS	= -lreadline
RM		= rm -rf

HEADER	= minishell.h

MPATH	= minishell.c line_read.c ft_split.c ft_strjoin.c path_env.c redirection.c
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