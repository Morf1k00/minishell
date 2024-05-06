/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:10:02 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/02 18:38:57 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	create_pipe(t_pipexbonus *ppxb)
{
	int	i;

	i = 0;
	while (i < ppxb->cmd_nbrs - 1)
	{
		if (pipe(ppxb->pipe + 2 * i) < 0)
			parent_free(ppxb);
		i++;
	}
}

void	close_pipe(t_pipexbonus *ppxb)
{
	int	i;

	i = 0;
	while (i < (ppxb->pipe_nbrs))
	{
		close(ppxb->pipe[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipexbonus	ppxb;

	if (argc < arguments_check(argv[1], &ppxb))
		return (msg(ERR_INPUT));
	if (get_infile(argv, &ppxb) == 2)
		return(0);
	get_outfile(argv[argc - 1], &ppxb);
	ppxb.cmd_nbrs = argc - 3 - ppxb.here_doc;
	ppxb.pipe_nbrs = 2 * (ppxb.cmd_nbrs - 1);
	ppxb.pipe = (int *)malloc(sizeof(int) * ppxb.pipe_nbrs);
	if (!ppxb.pipe)
		msg_error(ERR_PIPE);
	ppxb.env_paths = get_path(env);
	ppxb.cmd_paths = ft_split(ppxb.env_paths, ':');
	if (!ppxb.cmd_paths)
		pipe_free(&ppxb);
	create_pipe(&ppxb);
	ppxb.index = -1;
	while (++(ppxb.index) < ppxb.cmd_nbrs)
		child(ppxb, argv, env);
	close_pipe(&ppxb);
	waitpid(-1, NULL, 0);
	parent_free(&ppxb);
	return (0);
}
