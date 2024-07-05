/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:57 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/04 15:59:14 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokens_init(char *arv)
{
	if (arv[0] == '<' && !arv[1])
		return (LESS_THEN);
	else if (arv[0] == '<' && arv[1] == '<' && !arv[2])
		return (HEREDOC);
	else if (arv[0] == '>' && !arv[1])
		return (GREATER_THEN);
	else if (arv[0] == '>' && arv[1] == '>' && !arv[2])
		return (APPEND);
	else if (arv[0] == '|' && !arv[1])
		return (PIPE);
	else if (arv[0] != ' ')
		return (WORD);
	else
		return (SPACE_T);
}

char	**create_envp(void)
{
	char	**envp;
	char	cwd[100];

	envp = malloc(sizeof(char *) * 4);
	envp[0] = ft_strdup("SHLVL=1");
	envp[1] = ft_strdup("PATH=/bin/");
	if (getcwd(envp[1], 100))
		envp[2] = ft_strjoin("PWD=", cwd);
	else
	{
		ft_putstr_fd("getcwd() error\n", 2);
		exit(1);
	}
	envp[3] = NULL;
	return (envp);
}
