/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/14 16:45:00 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "unistd.h"
#include "stdlib.h"
#include <readline/readline.h>
#include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
#include <string.h>

typedef enum e_token
{
	WORD,
	PIPE,
	//SPACE,
	GREATER_THEN,
	LESS_THEN,
	HEREDOC,
	APPEND,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
}		t_type;

typedef struct s_pipes
{
	char **arv;
	char *cmd;
	char input;
	char output;
	int fd[2];
	char *heredoc;
}				t_pipes;

typedef struct s_vars
{
	int	lenght;
	char *token;
	int type;
	struct s_vars *next;
}			t_vars;

typedef struct s_env_path
{
	char	**env_paths;
	int		count;
	int last;
	t_pipes *pipes;
	t_vars	*vars;
}				t_env_path;

//extern t_env_path *env_shell;
typedef struct s_line
{
	char	**line_arg;
	int		arg_c;
}				t_line;
		
char	**line_read(char *line);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
// int		ft_strncmp(char *s1, char *s2, unsigned int n);
// void    path_e(char ***tmp, int *i, int *count, char **env);
void 	init_path(char **env, t_env_path *env_shell);
char 	*word_cpy(char *line);
char	**split_arg(char *line);
void lexer(char **line, t_env_path *env_shell);



