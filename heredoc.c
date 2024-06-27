/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:24:50 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/27 16:27:08 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void charjoin(char **buf, char c)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(*buf);
	tmp2 = ft_calloc(2, sizeof(char));
	tmp2[0] = c;
	*buf = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
}

// static void close_heredoc(char *file_name, char **buf)
// {
// 	int	fd;

// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 	}
// 	while ((fd, buf))
// 	{
// 		write(1, *buf, ft_strlen(*buf));
// 		write(1, "\n", 1);
// 	}
// 	close(fd);
// 	unlink(file_name);
// }

// void close_here(char *file, char **buf, t_env_path *env_shell)
// {
// 	free(buf);
// 	env_shell->pipe->heredoc = *file;
// }

void heredoc_min(char *line)
{
	char	*buf;
	char	*file_name;
	char	*limiter;
	int		fd;

	limiter = line;
	file_name = ft_strdup(".here_doc");
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		buf = readline("> ");
		charjoin(&buf, '\n');
		if (!buf)
		{
			free(buf);
			printf("ERORR WITH HEREDOC\n");
		}
		if (ft_strncmp(buf, limiter, ft_strlen(limiter)) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		free(buf);
	}
	close(fd);
	free(buf);
}
