# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:11:32 by rkrechun          #+#    #+#              #
#    Updated: 2024/05/15 19:10:08 by debizhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minihell
CC		= gcc #-g -fsanitize=address
FLAGS	= -Wall -Wextra -Werror
LIBS	= -lreadline
RM		= rm -rf

HEADER	= minishell.h

MPATH	= minishell.c \
		 ft_split.c \
		 env_init.c \
		 split_arg.c \
		 word_cpy.c \
		 lexer.c \
		 tokens.c \
		 tokens2.c \
		ft_echo.c 
OBJ_M	= $(MPATH:.c=.o)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_M)
	@make bonus -C libft
	@mv libft/libft.a .
	@$(CC) $(OBJ_M) $(LIBS) libft.a -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ_M)
	@make clean -C libft
	@rm libft.a
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft	
.PHONY: all clean fclean