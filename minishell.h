/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/17 17:15:24 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <string.h>

typedef enum e_token
{
	WORD,
	PIPE,
	SPACE_T,
	GREATER_THEN,
	LESS_THEN,
	HEREDOC,
	APPEND,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	CMD,
}		t_type;

typedef struct s_pipes
{
	char	**arv;
	char	*cmd;
	char	input;
	char	output;
	int		fd[2];
	char	*heredoc;
	int		count;
}	t_pipes; //пайпы и что с ними делать, исполнение в дальнейшем команд

typedef struct s_vars
{
	int				lenght;
	char			*token;// значения, аргумента
	int				type;// тип токена Word, space итд
	struct s_vars	*next;
}	t_vars; // листы с токенами и их значения 

typedef struct s_env_path
{
	char	**env_paths;
	int		count;
	int		last;
	t_pipes	*pipes;
	t_vars	*vars;
}	t_env_path; // основная структура 

//extern t_env_path *env_shell;
typedef struct s_line
{
	char	**line_arg;
	int		arg_c;
}	t_line;

char	**line_read(char *line);
char	**ft_split(char const *s, char c);
// void    path_e(char ***tmp, int *i, int *count, char **env);
void	init_path(char **env, t_env_path *env_shell);
char	*word_cpy(char *line);
char	**split_arg(char *line);
void	lexer(char **line, t_env_path *env_shell);
int		create_list(t_vars **list, char **arv);
int		tokens_init(char *arv);
bool	close_quote(char **line);
void	echo(t_vars **lst);
void	ft_listclear(t_vars **head);
void	ft_env(t_env_path *ep);
char	*get_pathd(char **env, int i, char *cmd);
int		len_pat(char *arv);
int		len_cats(char *arv, int len_path);
#endif