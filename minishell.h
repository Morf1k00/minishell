/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/03 14:05:04 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <signal.h>

typedef enum e_token
{
	WORD,
	PIPE,
	SPACE_T,
	GREATER_THEN,
	LESS_THEN,
	HEREDOC,
	APPEND,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	CMD,
	INVALID,
}	t_type;

typedef struct s_pipes
{
	char	**arv;
	char	*cmd;
	char	*input;
	char	*output;
	int		fd[2];
	int		pipe_i;
	char	*heredoc;
	int		count;
}	t_pipes;

typedef struct s_vars
{
	int				length;
	char			*token;
	int				type;
	struct s_vars	*next;
	struct s_vars	*prev;
}	t_vars;

typedef struct s_env_path
{
	char	**env_paths;
	char	*path;
	int		count;
	int		last;
	char	*shelllvl;
	int		last_exit_status;
	t_pipes	*pipes;
	t_vars	*vars;
}	t_env_path;

typedef struct s_pipe_info
{
	int			*pipe_fd;
	t_env_path	*data;
	char		**command;
	int			end;
	int			std_fd;
}		t_pipe_info;

void	free_exit(t_vars *list, t_env_path *env_shell);
char	**ft_split(char const *s, char c);
char	*word_cpy(char *line);
char	**split_arg(char *line);
void	lexer(char **line, t_env_path *env_shell);
void	create_list(t_vars **list, char **arv);
int		tokens_init(char *arv);
int		close_quote(char **line);
void	echo(t_vars **lst);
void	ft_listclear(t_vars **head);
void	ft_env(t_env_path *ep);
void	execute_export_command(char **args, t_env_path *env_shell);
void	init_path(char **env, t_env_path *env_shell);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	ft_error_exit(char *str);
int		lenpath(char *arv);
int		lencat(char *arv, int len_path);
void	ft_pwd(t_env_path *ep);
void	check_cmd(t_vars *list, t_env_path *env_shell);
void	command_to_do(t_vars *list, t_env_path *env_shell);
void	change_dir(t_env_path *env_shell, t_vars *list);
void	exit_file(t_vars *list, t_env_path *env_shell);
char	*get_pathd(char **end, int i, char *cmd);
char	*get_pathm(char **end);
char	**extract_cmd(char *cmd, char *path);
void	shell_lvl(t_env_path *env_shell);
void	execute_unset_command(char **args, t_env_path *env_shell);
void	execom(t_vars *list, t_env_path *env_shell);
void	setup_redirections(char **args);
void	check_pipe_line(t_env_path *env_shell);
void	sig_handle(int sig);
void	child_sig(void);
void	heredoc_sig_handle(int sig);
void	signals(void);
void	sig_handle_child(int sig);
void	heredoc_sig(void);
void	free_exit(t_vars *list, t_env_path *env_shell);
void	start_shell(t_env_path *env_shell);
char	*expand_variable(const char *token, t_env_path *env_shell);
void	heredoc_min(char *line);
void	check_heredoc(t_env_path *env_shell);
int		execute_pipe(t_env_path *data, char **arv, int num_commands);
void	close_pipes(int prev_fd, int *pipe_fd);
void	create_pipe(int *pipe_fd);
void	free_struct(t_env_path *env_shell);
void	set_type(t_vars *list, t_env_path *env_shell);
void	execute_command_external(char **args, char **line,
			t_env_path *env_shell);
char	**create_envp(void);

#endif