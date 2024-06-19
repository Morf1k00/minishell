/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:14:11 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/19 17:17:30 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int change_line_with_pipes(t_env_path *env_shell)
{
	int i;
	char **tmp;

	i = 0;
	tmp = env_shell->pipes->arv;
	while (tmp[i] != NULL)
	{
		if (tmp[i][0] == '|' && tmp[i][1] == '|')
		{	
			tmp[i - 1] = NULL;
			while (tmp[i] != NULL)
			{
				tmp[i] = NULL;
				i++;
			}
			env_shell->pipes->arv = tmp;
			return(1);
		}
		if (tmp[i] != NULL)
			i++;
	}
	return(0);
}

int count_elements(char **tmp, int i)
{
	int count;

	count = 0;
	while(tmp[i] != NULL)
	{
		count++;
		i++;
	}
	return(count);
}

void removes_string(t_env_path *env_shell)
{
	int i;
	char **tmp;
	char **new;
	int j;
	int count;
	
	i = 0;
	tmp = env_shell->pipes->arv;
	while(tmp && tmp[i][0] != '|' )
		i++;
	printf("i = %d\n", i);
	count = count_elements(tmp, i);
	new = malloc(sizeof(char *) * (count + 1));
	i += 2;
	j = 0;
	while(tmp && tmp[i] != NULL)
	{
		new[j] = ft_strdup(tmp[i]);
		i++;
		j++;
	}
	new[j] = NULL;
	env_shell->pipes->arv = new;

}

void check_redirection(t_env_path *env_shell)
{
	int i;
	char **tmp;
	int p;

	i = 0;
	p = env_shell->pipes->pipe_i;
	tmp = env_shell->pipes->arv;
	// printf("p = %d\n", p);
	while(tmp && tmp[i] != NULL && p != 0 && tmp[i][0] != '>' && tmp[i][0] != '<')
	{	if (tmp[i][0] == '|')
			p--;// проверить роьоту с пайпами и редирекшонами 
		i++;}
	// printf("p = %d\n", p);
	if (tmp[i - 1][0] == '|')
	{
		// printf("output = %s\n", env_shell->pipes->output);
		while(tmp && tmp[i] != NULL)
		{
			if(tmp[i][0] == '>')
				env_shell->pipes->output = ft_strdup(tmp[i + 2]);
			else if(tmp[i][0] == '>' && tmp[i][1] == '>')
				env_shell->pipes->output = tmp[i + 2];
			i++;
		}
		// printf("output = %s\n", env_shell->pipes->output);
		if (!env_shell->pipes->output )
			removes_string(env_shell);
	}
}

void	check_pipe_line(t_env_path *env_shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (change_line_with_pipes(env_shell) == 1)
		env_shell->pipes->pipe_i = 0;
	else
	{
		while (env_shell->pipes->arv[i] != NULL)
		{
			if (env_shell->pipes->arv[i][0] == '|'
				&& env_shell->pipes->arv[i][1] == '\0')
				j++;
			i++;
			env_shell->pipes->pipe_i = j;
		}
		check_redirection(env_shell);
	}
}
