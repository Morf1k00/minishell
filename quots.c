/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/17 17:08:49 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_single_quote(char **line, int *i, int *sq)
{
	(*sq)++;
	(*i)++;
	if (!line[*i])
		return (false);
	while (line[*i][0] != '\'' && line[*i])
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
	while (line[*i][0] != '\"' && line[*i])
		(*i)++;
	if (!line[*i])
		return (false);
	(*dq)++;
	return (true);
}

bool	close_quote(char **line)
{
	int	i;
	int	sq;
	int	dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (line[i])
	{
		if (line[i][0] == '\'')
		{
			if (!check_single_quote(line, &i, &sq))
				return (false);
		}
		else if (line[i][0] == '\"')
		{
			if (!check_double_quote(line, &i, &dq))
				return (false);
		}
		if (line[i] != NULL)
			i++;
			i++;
	}
	if (sq % 2 == 0 && dq % 2 == 0)
		return (true);
	return (false);
		return (true);
	return (false);
}

