/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:42:36 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/17 17:08:49 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pathm(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

// char	*get_pathd(char **env, int i, char *cmd)
// {
// 	while (ft_strcmp(cmd, *env, i))
// 		env++;
// 	return (*env + i);
// }

int	len_pat(char *arv)
{
	int	len;

	len = 0;
	while (arv[len])
		len++;
	return (len);
}

int	len_cats(char *arv, int len_path)
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

void	ft_listclear(t_vars **head)
{
	t_vars	*current;
	t_vars	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
