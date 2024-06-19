/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:09:58 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/19 15:53:24 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	msg(char *n)
{
	write(2, n, ft_strlen(n));
	return (1);
}

void	msg_error(char *n)
{
	perror(n);
	exit(1);
}

// int	msg_error_i(char *n, t_pipexbonus *p)
// {
// 	// int i;
	
// 	// i = 0;
// 	write(2, n, ft_strlen(n));
// 	write(2, "\n", 1);
// 	// if (p->infile < 0)
// 	// 	i = 1;
// 	return(0);
// }

void	msg_pipe(char *n)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	write(2, n, ft_strlen(n));
	write(2, "\n", 1);
}
