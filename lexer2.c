/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:52:30 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/25 17:42:46 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_arv(char **line, char **tmp, int *i, int *j)
{
	int	len;
	int	d;

	len = 1;
	d = *i;
	while (line[d] != NULL)
	{
		len += ft_strlen(line[d]);
		d++;
	}
	tmp[*j] = malloc(sizeof(char) * (len + 1));
	tmp[*j][0] = '\0';
	while (*i < d)
	{
		strcat(tmp[*j], line[*i]);
		(*i)++;
	}
	tmp[*j][len] = '\0';
	(*i)++;
}

static int	word_count(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		i++;
	return (i);
}

void	lexer2(char **line, t_env_path *env_shell)
{
	int		i;
	int		j;
	char	**tmp;
	int		word;

	i = 0;
	j = 0;
	word = word_count(line);
	tmp = malloc(sizeof(char *) * (word + 1));
	while (i < word)
	{
		if (line[i][0] == '\'' || line[i][0] == '\"')
			copy_arv(line, tmp, &i, &j);
		else
		{
			tmp[j] = strdup(line[i]);
			i++;
		}
		j++;
	}
	tmp[j] = NULL;
	env_shell->pipes->arv = tmp;
	env_shell->pipes->count = j;
}
