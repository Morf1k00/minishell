/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/08 18:31:53 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct s_pipes
{
	char	**arv;
	char	*cmd;
	char	input;
	char	output;
	int		fd;
	char	*heredoc;
}				t_pipes;

typedef enum e_token
{
	WORD,
	PIPE,
	GREAT,
	LESS,
	GREATGREAT,
	LESSLESS,
	G_AMP,
	AMPERSAND,
	QUOTES,
	SPACE,
	D_QUOTES
} t_type;

typedef struct s_token
{
	int				type;
	char			*rprsnt;
	struct s_token	next;
}	t_token;

typedef struct s_env_path
{
	char	**env_paths;
	char	**env_cmd_path;
	char	**cmd_paths;
	int		count;
	int		last;
}				t_env_path;

typedef struct s_line
{
	char	*line_1;
	char	**line_trim;
	int		arg_c;
}				t_line;

//char	**line_read(char *line);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	init_path(char **env);
char**	line_read(char *line);
void	ft_redirect_cmd_to_file(char **command, char *output_file);
void	error_exit(char *str);

#endif
