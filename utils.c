/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:42:36 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/17 14:49:58 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/ft_strncmp.c"

char	*get_pathm(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

char	*get_pathd(char **env, int i, char *cmd)
{
	while (ft_strncmp(cmd, *env, i))
		env++;
	
	return (*env + i);
}

int lenpath(char *arv)
{
	int len;

	len = 0;
	while (arv[len] != NULL)
		len++;
	return (len);
}

int lencat(char *arv, int len_path)
{
	int len;

	len = 0;
	while (arv[len_path] != '/')
	{	
		len_path--;
		len++;
	}
	return(len);	
}
