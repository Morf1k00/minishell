/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:01:24 by debizhan          #+#    #+#             */
/*   Updated: 2024/06/26 16:43:21 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>
#include <string.h>
#include "minishell.h"

char	*get_env_value(const char *name, t_env_path *env_shell)
{
	int		i;
	size_t	name_len;

	i = 0;
	name_len = ft_strlen(name);
	while (env_shell->env_paths[i])
	{
		if (ft_strncmp(env_shell->env_paths[i], name, name_len) == 0
			&& env_shell->env_paths[i][name_len] == '=')
			return (env_shell->env_paths[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

static char	*expands_variable2(char *var_start,
	char *var_end, const char *token, char *var_value)
{
	size_t	prefix_len;
	size_t	suffix_len;
	char	*expanded;

	prefix_len = var_start - token;
	suffix_len = ft_strlen(var_end);
	expanded = malloc(prefix_len + ft_strlen(var_value) + suffix_len + 1);
	ft_strncpy(expanded, token, prefix_len);
	ft_strcpy(expanded + prefix_len, var_value);
	ft_strcpy(expanded + prefix_len + ft_strlen(var_value), var_end);
	return (expanded);
}

char	*expand_variable(const char *token, t_env_path *env_shell)
{
	char	*var_start;
	char	*var_end;
	char	*var_name;
	char	*var_value;
	size_t	var_name_len;

	var_start = ft_strchr(token, '$');
	if (!var_start)
		return (ft_strdup(token));
	var_end = var_start + 1;
	while (*var_end && (ft_isalnum(*var_end) || *var_end == '_'))
		var_end++;
	var_name_len = var_end - var_start - 1;
	var_name = malloc(var_name_len + 1);
	ft_strncpy(var_name, var_start + 1, var_name_len);
	var_name[var_name_len] = '\0';
	var_value = get_env_value(var_name, env_shell);
	free(var_name);
	if (!var_value)
		return (ft_strdup(token));
	return (expands_variable2(var_start, var_end, token, var_value));
}
