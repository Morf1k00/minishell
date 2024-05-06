/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:05:55 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/02 17:33:23 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	arguments_check(char *args, t_pipexbonus *ppxb)
{
	if (args && !ft_strncmp("here_doc", args, 9))
	{
		ppxb->here_doc = 1;
		return (6);
	}
	else
	{
		ppxb->here_doc = 0;
		return (5);
	}
}

void	here_doc(char *delimiter, t_pipexbonus *ppxb)
{
	int		file;
	char	*buf;

	file = open (".heredoc_tmp", O_CREAT | O_WRONLY, 0644);
	if (file < 0)
		msg_error(ERR_HEREDOC);
	while (1)
	{
		write (1, "heredoc> ", 9);
		if (get_next_line(0, &buf) < 0)
			exit(1);
		if (!ft_strncmp(delimiter, buf, ft_strlen(delimiter) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	ppxb->infile = open(".heredoc_tmp", O_RDONLY);
	if (ppxb->infile < 0)
	{
		unlink(".heredoc_tmp");
		msg_error(ERR_HEREDOC);
	}
}
