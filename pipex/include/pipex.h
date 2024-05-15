/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:05:27 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/02 17:03:23 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../gnl/get_next_line.h"

# define ERR_INFILE "No such file or directory"
# define ERR_OUTFILE "OUTFILE"
# define ERR_PIPE "PIPE"
# define ERR_INPUT "INVALID NUMBER OF ARGUMENTS.\n"
# define ERR_CMD "COMAND NOT FOUND\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	*paths;
	char	**cmd_path;
	char	**cmd_args;
}				t_pipex;

// childs.c
void			first_child(t_pipex pipex, char *argv[], char *evnp[]);
void			second_child(t_pipex pipex, char *argv[], char *evnp[]);

// error.c
int				msg(char *err);
int				msg_error(char *err);

// free.c
void			parent_free(t_pipex *pipex);
void			childs_free(t_pipex *pipex);

// pipex.c
char			*find_path(char **evn);
void			close_pipes(t_pipex *pipex);

// function
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strdup(const char *src);

#endif