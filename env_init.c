/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:34 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/21 17:33:30 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_path(char **env, t_env_path *env_shell)
{
	char	**tmp;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (env[count])
		count++;
	tmp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tmp)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (i < count)
	{
		tmp[i] = strdup(env[i]);
		i++;
	}
	tmp[i] = NULL;
	env_shell->count = count;
	env_shell->env_paths = tmp;
	env_shell->last = 0;
	env_shell->pipes = malloc(sizeof(t_pipes));
	if (!env_shell->pipes)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
}
