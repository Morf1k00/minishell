/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:42:28 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 16:56:11 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

int	msg_error(char *err)
{
	perror(err);
	exit(1);
}
