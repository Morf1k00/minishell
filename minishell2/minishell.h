/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/10 11:59:02 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "unistd.h"
#include "stdlib.h"
#include <readline/readline.h>
#include <readline/history.h>
# include <fcntl.h>

typedef struct s_pipes
{
	char **arv;
	char *cmd;
	char input;
	char output;
	int fd[2];
	char *heredoc;
}				t_pipes;

typedef struct s_env_path
{
	char	**env_paths;
	int		count;
	int last;
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
int		ft_strncmp(char *s1, char *s2, unsigned int n);
// void    path_e(char ***tmp, int *i, int *count, char **env);
void 	init_path(char **env, t_env_path *env_shell);
char 	*word_cpy(char *line);
char	**split_arg(char *line);



