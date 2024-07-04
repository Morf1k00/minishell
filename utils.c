/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:42:36 by debizhan          #+#    #+#             */
/*   Updated: 2024/07/04 14:35:16 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pathm(char **end)
{
	while (ft_strncmp("PATH", *end, 4))
		end++;
	return (*end + 5);
}

char	*get_pathd(char **end, int i, char *cmd)
{
	while (ft_strncmp(cmd, *end, i))
		end++;
	return (*end + i);
}

int	lenpath(char *arv)
{
	int	len;

	len = 0;
	while (arv[len])
		len++;
	return (len);
}

int	lencat(char *arv, int len_path)
{
	int	len;

	len = 0;
	while (arv[len_path] != '/')
	{
		len_path--;
		len++;
	}
	return (len);
}

void	ft_listclear(t_vars **list)
{
	t_vars	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->token);
		free(*list);
		*list = tmp;
	}
}
