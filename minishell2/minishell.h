/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/08 16:08:35 by rkrechun         ###   ########.fr       */
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
	int fd;
	char *heredoc;
}				t_pipes;

typedef struct s_env_path
{
	char	**env_paths;
	char	**env_cmd_path;
	char	**cmd_paths;
	int		count;
	int last;
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


