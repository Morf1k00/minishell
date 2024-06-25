/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:47:07 by debizhan          #+#    #+#             */
/*   Updated: 2024/06/25 17:12:01 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_vars	*new_list(char *arg, t_env_path *env_shell)
{
	t_vars	*list;

	list = malloc(sizeof(t_vars));
	if (!list)
		return (NULL);
	list->length = ft_strlen(arg);
	list->type = tokens_init(arg);
	list->token = arg;
	if (list->type == WORD)
		check_cmd(list, env_shell);
	list->next = NULL;
	return (list);
}

static void	list_add(t_vars **lst, t_vars *new)
{
	t_vars	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	create_list(t_vars **list, char **arv, t_env_path *env_shell)
{
	int		i;
	t_vars	*new_node;
	t_vars	*file_node;

	i = 0;
	while (arv[i])
	{
		new_node = new_list(arv[i++], env_shell);
		list_add(list, new_node);
		if (new_node->type == GREATER_THEN
			|| new_node->type == APPEND || new_node->type == LESS_THEN)
		{
			if (arv[i] == NULL)
			{
				printf("minishell: syntax error near unexpected token\n");
				return ;
			}
			file_node = new_list(arv[i++], env_shell);
			list_add(list, file_node);
		}
	}
}
