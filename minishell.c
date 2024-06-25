/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/25 17:41:41 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pipe(t_env_path *data, char **arv, int num_commands);
// static void	print_list(t_vars **lst)
// {
// 	t_vars	*tmp;

// 	tmp = *lst;
// 	while (tmp)
// 	{
// 		printf("info: %s\ttype: %d\tlength: %d\n", tmp->token, tmp->type, tmp->length);
// 		tmp = tmp->next;
// 	}
// }

static void	init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
	(void)argc;
	(void)argv;
	init_path(env, env_shell);
	env_shell->path = get_pathm(env_shell->env_paths);
}

static void	edit_line_withot_spaces(t_env_path *env_shell, t_vars *list)
{
	char	**tmp;
	int		i;
	t_vars	*tmp_list;
	int		j;

	i = 0;
	j = 0;
	tmp_list = list;
	tmp = malloc(sizeof(char *) * 20);
	while (tmp_list)
	{
		if (tmp_list->type == SPACE_T)
			tmp_list = tmp_list->next;
		else
		{
			tmp[i] = ft_strdup(tmp_list->token);
			i++;
			tmp_list = tmp_list->next;
		}
	}
	tmp[i++] = NULL;
	free(env_shell->pipes->arv);
	env_shell->pipes->arv = tmp;
	while (env_shell->pipes->arv[j])
		printf("arv[%d]: %s\n", j, env_shell->pipes->arv[j++]);
}

int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**line;
	t_env_path	*env_shell;
	t_vars		*list;
	int			num_commands;

	list = NULL;
	env_shell = malloc(sizeof(t_env_path));
	init_arg(argc, argv, env, env_shell);
	start_shell(env_shell);
	while (1)
	{
		input = readline("minishell: ");
		if (!input)
			break ;
		add_history(input);
		line = split_arg(input);
		env_shell->last = close_quote(line);
		if (env_shell->last == 0)
		{
			lexer(line, env_shell);
			check_pipe_line(env_shell);
			create_list(&list, env_shell->pipes->arv, env_shell);
			if (env_shell->pipes->pipe_i > 0)
			{
				num_commands = env_shell->pipes->pipe_i + 1;
				edit_line_withot_spaces(env_shell, list);
				execute_pipe(env_shell, env_shell->pipes->arv, num_commands);
			}
			else
			{
				edit_line_withot_spaces(env_shell, list);
				execom(list, env_shell);
			}
		}
		else
			exit_file(list, env_shell);
		ft_listclear(&list);
		free(input);
	}
	return (0);
}
