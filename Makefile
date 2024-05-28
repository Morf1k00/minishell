# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:11:32 by rkrechun          #+#    #+#              #
#    Updated: 2024/05/28 17:16:03 by rkrechun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC		=	gcc #-g -fsanitize=address
FLAGS	=	-Wall -Wextra -Werror
LIBS	=	-lreadline
RM		=	rm -rf

HEADER	=	minishell.h

MPATH	=	minishell.c \
			ft_split.c \
			env_init.c \
			split_arg.c \
			word_cpy.c \
			lexer.c \
			tokens.c \
			tokens2.c \
			echo.c \
			utils.c \
			utils2.c \
			env.c \
			quots.c \
			export.c \
			error_handler.c \
			loop_to_do.c\
			cd.c\
			pars_cmd.c\
			exit_min.c\
			extract_cmd.c\
			unset.c\
			redirection.c\
			built-ins.c\
			pipes_fork.c\
			#free_exit.c\
			
			
OBJ_M	= $(MPATH:.c=.o)

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_M)
	@$ make bonus -C libft
	@$ mv libft/libft.a .
	@$(CC) $(OBJ_M) $(LIBS) libft.a -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ_M)
	@make clean -C libft
	@rm libft.a
fclean: clean
	@$(RM) $(NAME)
.PHONY: all clean fclean