/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:46:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/04 17:00:47 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
	(void)argc;
	(void)argv;
	init_path(env, env_shell);
	start_shell(env_shell);
	env_shell->path = get_pathm(env_shell->env_paths);
}

static void	edit_line_withot_spaces(t_env_path *env_shell, t_vars *list)
{
	char	**tmp;
	int		i;
	t_vars	*tmp_list;

	i = 0;
	tmp_list = list;
	tmp = malloc (sizeof(char *) *(20));
	while (tmp_list)
	{
		if (tmp_list->type == SPACE_T)
			tmp_list = tmp_list->next;
		else
		{
			tmp[i] = tmp_list->token;
			i++;
			tmp_list = tmp_list->next;
		}
	}
	tmp[i++] = NULL;
	free(env_shell->pipes->arv);
	env_shell->pipes->arv = tmp;
}

static void	ifdo(char **line, t_env_path *env_shell, t_vars *list)
{
	int		num_commands;

	lexer(line, env_shell);
	free_array(line);
	check_pipe_line(env_shell);
	check_heredoc(env_shell);
	create_list(&list, env_shell->pipes->arv);
	set_type(list, env_shell);
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
	ft_listclear(&list);
	free_array(env_shell->pipes->arv);
}

static void	whileloop(t_vars *list, t_env_path *env_shell)
{
	char	*input;
	char	**line;

	setup_signal_handlers();
	while (1)
	{
		input = readline("minishell: ");
		if (!input)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			cleanup(env_shell, list);
			exit(0);
		}
		add_history(input);
		line = split_arg(input);
		env_shell->last = close_quote(line);
		if (env_shell->last == 0)
			ifdo(line, env_shell, list);
		else
			exit_file(list, env_shell);
		if (access(".here_doc", F_OK) == 0)
			unlink(".here_doc");
		ft_listclear(&list);
		free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_env_path	*env_shell;
	t_vars		*list;
	char		**envp;

	list = NULL;
	env_shell = malloc(sizeof(t_env_path));
	if (!*env)
	{
		envp = create_envp();
		init_arg(argc, argv, envp, env_shell);
	}
	else
		init_arg(argc, argv, env, env_shell);
	whileloop(list, env_shell);
	return (0);
}
