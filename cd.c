/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:13:09 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/16 16:13:03 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void change_dir(t_env_path *env_shell)
{
	t_vars **list;
	char **tmp;

	while (list->next)
	{
		//list = list->next
		if (list->type == SPACE_T)
			list = list->next;
		if (list->type == WORD)
		{
			if(list->token[0] == '/')
				absolute_path(list->token);
			else if (list->token[0] == '~')
				
			else if (list->token[0] == '.' && list->token[1] == '.')
				
			else if ((list->token[0] == '\'' || list->token[0] == '\"') &&
					(list->token[1] == '.' && list->token[2] == '.'))
					
			else if ((list->token[0] == '\'' || list->token[0] == '\"')
						&& list->token[0] != ' ')
						
			else if (list->token[0] != ' ')
				
		}
	}
}