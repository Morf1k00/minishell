/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:03:52 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/21 17:50:58 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_export_command(char *input, char **name, char **value)
{
	char	*equal_sign;

	equal_sign = strchr(input, '=');
	if (equal_sign == NULL)
		return (-1);
	*equal_sign = '\0';
	*name = strdup(input);
	*value = strdup(equal_sign + 1);
	return (0);
}

void	upd_env_var(t_env_path *env_shell, char *name, char *value)
{
	int	i;
	int	len;

	i = -1;
	while (++i < env_shell->count)
	{
		if (strncmp(env_shell->env_paths[i], name, strlen(name)) == 0 && env_shell->env_paths[i][strlen(name)] == '=')
		{
			free(env_shell->env_paths[i]);
			len = strlen(name) + strlen(value) + 2;
			env_shell->env_paths[i] = (char *)malloc(len);
			if (!env_shell->env_paths[i])
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(env_shell->env_paths[i], name);
			strcat(env_shell->env_paths[i], "=");
			strcat(env_shell->env_paths[i], value);
			return ;
		}
	}
	env_shell->env_paths = (char **)realloc(env_shell->env_paths, sizeof(char *) * (env_shell->count + 2));
	if (!env_shell->env_paths)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	len = strlen(name) + strlen(value) + 2;
	env_shell->env_paths[env_shell->count] = (char *)malloc(len);
	if (!env_shell->env_paths[env_shell->count])
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(env_shell->env_paths[env_shell->count], name);
	strcat(env_shell->env_paths[env_shell->count], "=");
	strcat(env_shell->env_paths[env_shell->count], value);
	env_shell->count++;
	env_shell->env_paths[env_shell->count] = NULL;
}

void	execute_export_command(char **args, t_env_path *env_shell)
{
	char	*name;
	char	*value;

	if (args[1] == NULL)
	{
		write(2, "export: not enough arguments\n", 29);
		return ;
	}
	printf("args[1]: %s\n", args[2]);
	if (parse_export_command(args[2], &name, &value) == 0)
	{
		upd_env_var(env_shell, name, value);
		free(name);
		free(value);
	}
	else
	{
		write(2, "export: invalid format\n", 23);
	}
}
