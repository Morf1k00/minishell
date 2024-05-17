/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:55:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/17 15:50:42 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// #include "libft/ft_strjoin.c"

void	ft_error_exit(char *str);

void	ft_redirect_cmd_to_file(char **command, char *output_file)
{
	pid_t	pid;
	int		fd;
	int		status;
	char	*path;
	char	*cmd;

	pid = fork();
	if (pid < 0)
		ft_error_exit("fork");
	else if (pid == 0)
	{
		fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1)
			ft_error_exit("open");
		if (dup2(fd, STDOUT_FILENO) == -1)
			ft_error_exit("dup2");
		close(fd);
		if (execve(command[0], command, NULL) == -1)
			ft_error_exit("execve");
	}
}

// int	main()
// {

// 	char *command[] = {"/bin/ls", NULL};
//     char *output_file = "output.txt";

// 	ft_redirect_cmd_to_file(command, output_file);
// }