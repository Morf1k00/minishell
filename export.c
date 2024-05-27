/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:03:52 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/27 17:20:47 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_export_command(char *input, char **name, char **value)
{
	char	*equal_sign;
	size_t	name_len;
	size_t	value_len;

	equal_sign = strchr(input, '=');
	if (equal_sign == NULL)
	{
		return (-1);
	}
	name_len = equal_sign - input;
	value_len = strlen(equal_sign + 1);
	*name = malloc(name_len + 1);
	*value = malloc(value_len + 1);
	if (*name == NULL || *value == NULL)
	{
		free(*name);
		free(*value);
		return (-1);
	}
	strncpy(*name, input, name_len);
	(*name)[name_len] = '\0';
	strcpy(*value, equal_sign + 1);
	return (0);
}

static void	ft_add_var(t_env_path *env_shell, char *name, char *value, int i)
{
	int	len;

	len = ft_strlen(name) + ft_strlen(value) + 2;
	env_shell->env_paths[i] = (char *)malloc(len);
	if (!env_shell->env_paths[i])
		ft_error_exit("malloc");
	strcpy(env_shell->env_paths[i], name);
	strcat(env_shell->env_paths[i], "=");
	strcat(env_shell->env_paths[i], value);
}

void	upd_env_var(t_env_path *env_shell, char *name, char *value)
{
	int	i;

	i = -1;
	while (++i < env_shell->count)
	{
		if (ft_strncmp(env_shell->env_paths[i], name, ft_strlen(name)) == 0
			&& env_shell->env_paths[i][ft_strlen(name)] == '=')
		{
			free(env_shell->env_paths[i]);
			ft_add_var(env_shell, name, value, i);
			return ;
		}
	}
	env_shell->env_paths = (char **)ft_realloc(env_shell->env_paths,
			sizeof(char *) * env_shell->count,
			sizeof(char *) * (env_shell->count + 1));
	if (!env_shell->env_paths)
		ft_error_exit("realloc");
	ft_add_var(env_shell, name, value, env_shell->count);
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

// void execute_export_command(char **args, t_env_path *env_shell)
// {
//     char *name, *value;
//     char *equal_sign = strchr(args[2], '=');

//     if (equal_sign == NULL)
//     {
//         write(2, "export: invalid format\n", 23);
//         return;
//     }

//     *equal_sign = '\0'; // Split the input string at '='
//     name = strdup(args[2]); // Copy the variable name
//     value = strdup(equal_sign + 1); // Copy the variable value

//     if (!name || !value)
//     {
//         perror("strdup");
//         free(name);
//         free(value);
//         return;
//     }

//     // Check if the variable already exists
//     for (int i = 0; i < env_shell->count; i++)
//     {
//         if (strncmp(env_shell->env_paths[i], name, strlen(name)) == 0 && env_shell->env_paths[i][strlen(name)] == '=')
//         {
//             // Update the existing environment variable
//             free(env_shell->env_paths[i]);
//             env_shell->env_paths[i] = malloc(strlen(name) + strlen(value) + 2);
//             if (!env_shell->env_paths[i])
//             {
//                 perror("malloc");
//                 free(name);
//                 free(value);
//                 exit(EXIT_FAILURE);
//             }
//             sprintf(env_shell->env_paths[i], "%s=%s", name, value);
//             free(name);
//             free(value);
//             return;
//         }
//     }

//     // Add a new environment variable
//     char **new_env_paths = realloc(env_shell->env_paths, sizeof(char *) * (env_shell->count + 2));
//     if (!new_env_paths)
//     {
//         perror("realloc");
//         free(name);
//         free(value);
//         exit(EXIT_FAILURE);
//     }
//     env_shell->env_paths = new_env_paths;
//     env_shell->env_paths[env_shell->count] = malloc(strlen(name) + strlen(value) + 2);
//     if (!env_shell->env_paths[env_shell->count])
//     {
//         perror("malloc");
//         free(name);
//         free(value);
//         exit(EXIT_FAILURE);
//     }
//     sprintf(env_shell->env_paths[env_shell->count], "%s=%s", name, value);
//     env_shell->count++;
//     env_shell->env_paths[env_shell->count] = NULL;
//     free(name);
//     free(value);
// }
