/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:35:10 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/19 18:33:09 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*word_cpy(char *line)
{
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	len = 0;
	while (line[len] != '\'' && line[len] != '\"' && line[len] != '\n'
		&& line[len] != '\t' && line[len] != '\0' && line[len] != ' ')
		len++;
	tmp = malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	while (i < len)
	{
		tmp[i] = line[i];
		i++;
	}
	return (tmp);
}
