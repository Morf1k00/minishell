/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:09:28 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/02 18:59:45 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static char	*get_command(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

static void	sub_dup2(int zero, int one)
{
	dup2(zero, 0);
	dup2(one, 1);
}

void	child(t_pipexbonus p, char **argv, char **envp)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.index == 0)
			sub_dup2(p.infile, p.pipe[1]);
		else if (p.index == p.cmd_nbrs - 1)
			sub_dup2(p.pipe[2 * p.index - 2], p.outfile);
		else
			sub_dup2(p.pipe[2 * p.index - 2], p.pipe[2 * p.index + 1]);
		close_pipe(&p);
		p.cmd_args = ft_split(argv[2 + p.here_doc + p.index], ' ');
		p.cmd = get_command(p.cmd_paths, p.cmd_args[0]);
		if (!p.cmd)
		{
			msg_pipe(p.cmd_args[0]);
			child_free(&p);
			exit(1);
		}
		execve(p.cmd, p.cmd_args, envp);
	}
}
