/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:47:07 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/22 14:12:39 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_vars	*new_list(char *arg, t_env_path *env_shell)
{
	t_vars	*list;

	list = malloc(sizeof(t_vars));
	if (!list)
		return (NULL);
	list->lenght = ft_strlen(arg);
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

int	create_list(t_vars **list, char **arv, t_env_path *env_shell)
{
	int	i;

	i = 0;
	if (!list || !arv)
		return (0);
	while (arv[i])
		list_add(list, new_list(arv[i++], env_shell));
	return (1);
}
