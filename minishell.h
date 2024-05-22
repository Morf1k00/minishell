/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/22 16:04:11 by debizhan         ###   ########.fr       */
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
}	t_type;

typedef struct s_pipes
{
	char	**arv;
	char	*cmd;
	char	input;
	char	output;
	int		fd[2];
	char	*heredoc;
	int		count;
}	t_pipes;

typedef struct s_vars
{
	int				length;
	char			*token;
	int				type;
	struct s_vars	*next;
}	t_vars;

typedef struct s_env_path
{
	char	**env_paths;
	int		count;
	int		last;
	t_pipes	*pipes;
	t_vars	*vars;
}	t_env_path;

typedef struct s_line
{
	char	**line_arg;
	int		arg_c;
}	t_line;

char	**line_read(char *line);
char	**ft_split(char const *s, char c);
char	*word_cpy(char *line);
char	**split_arg(char *line);
void	lexer(char **line, t_env_path *env_shell);
int		create_list(t_vars **list, char **arv);
int		tokens_init(char *arv);
bool	close_quote(char **line);
void	echo(t_vars **lst);
void	ft_listclear(t_vars **head);
void	ft_env(t_env_path *ep);
char	*get_pathd(char **env, int i, char *cmd);
int		len_pat(char *arv);
int		len_cats(char *arv, int len_path);
void	execute_export_command(char **args, t_env_path *env_shell);
void	init_path(char **env, t_env_path *env_shell);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	ft_error_exit(char *str);

#endif