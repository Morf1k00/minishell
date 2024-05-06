/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/06 18:56:50 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "unistd.h"
#include "stdlib.h"
#include <readline/readline.h>
#include <readline/history.h>
# include <fcntl.h>

typedef struct s_cmd_data
{
	char	*cmd;
	char	*env_paths;
	char	**cmd_paths;
	char	**cmd_args;
}				t_cmd_data;

char **line_read(char *line);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

