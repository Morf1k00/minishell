/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:13 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/27 17:19:11 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_environment_variable(t_env_path *env_shell, char *name)
{
	int	i;
	int	j;
	int	len;

	len = strlen(name);
	i = 0;
	while (i < env_shell->count)
	{
		if (strncmp(env_shell->env_paths[i], name, len) == 0
			&& env_shell->env_paths[i][len] == '=')
		{
			free(env_shell->env_paths[i]);
			j = i;
			while (j < env_shell->count - 1)
			{
				env_shell->env_paths[j] = env_shell->env_paths[j + 1];
				j++;
			}
			env_shell->env_paths[j] = NULL;
			env_shell->count--;
			return ;
		}
		i++;
	}
}

// void	print_env_variables(t_env_path *env_shell)
// {
// 	int	i;

// 	for (i = 0; i < env_shell->count; i++)
// 	{
// 		printf("env_paths[%d]: %s\n", i, env_shell->env_paths[i]);
// 	}
// }

void	execute_unset_command(char **args, t_env_path *env_shell)
{
	if (args[2] == NULL)
	{
		write(2, "unset: not enough arguments\n", 28);
		return ;
	}
	remove_environment_variable(env_shell, args[2]);
}
