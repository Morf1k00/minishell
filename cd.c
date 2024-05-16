/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:13:09 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/16 17:40:09 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void absolute_path(char *list)
{
	
}

void parent_dir(char *list, t_env_path *env_shell)
{
	char *path;
	char *old_path;
	int len_path;
	int len_cat;

	path = get_pathd(env_shell->env_paths, 3, "PWD");
	old_path = path;
	len_path = len_pat(path);
	len_cat = len_cats(path, len_path);
	ft_substr()
	
}

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
				parent_dir(list->token, env_shell);
			else if ((list->token[0] == '\'' || list->token[0] == '\"') &&
					(list->token[1] == '.' && list->token[2] == '.'))
					
			else if ((list->token[0] == '\'' || list->token[0] == '\"')
						&& list->token[0] != ' ')
						
			else if (list->token[0] != ' ')
				
		}
	}
}

OLDPWD=/
SHELL=/bin/zsh
PWD=/home/rkrechun/Desktop/minishell
