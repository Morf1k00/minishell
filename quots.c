/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/04 16:18:48 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_single_quote(char **line, int *i, int *sq)
{
	(*sq)++;
	(*i)++;
	if (!line[*i])
		return (false);
	while (line[*i] && line[*i][0] != '\'')
		(*i)++;
	if (!line[*i])
		return (false);
	(*sq)++;
	return (true);
}

static bool	check_double_quote(char **line, int *i, int *dq)
{
	(*dq)++;
	(*i)++;
	if (!line[*i])
		return (false);
	while (line[*i] && line[*i][0] != '\"')
		(*i)++;
	if (!line[*i])
		return (false);
	(*dq)++;
	return (true);
}

int	close_quote(char **line)
{
	int	i;
	int	sq;
	int	dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (line[i] != NULL)
	{
		if (line[i][0] == '\'' && line[i] != NULL)
		{
			if (!check_single_quote(line, &i, &sq))
				return (1);
		}
		else if (line[i][0] == '\"' && line[i] != NULL)
			if (!check_double_quote(line, &i, &dq))
				return (2);
		if (line[i] != NULL)
			i++;
	}
	if (sq % 2 == 0 && dq % 2 == 0)
		return (0);
	return (3);
}
