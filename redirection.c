/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:55:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/08 16:12:42 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect_cmd_to_file(char **command, char *output_file)
{
	pid_t	pid;
	int		fd;
	int		status;

	pid = fork();
	if (pid < 0)
		error_exit("fork");
	else if (pid == 0)
	{
		fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1)
			error_exit("open");
		if (dup2(fd, STDOUT_FILENO) == -1)
			error_exit("dup2");
		close(fd);
		if (execve(command[0], command, NULL) == -1)
			error_exit("execve");
	}
	else
		if (waitpid(pid, &status, 0) == -1)
			error_exit("waitpid");
}

// int main() {
//     char *command[] = {"/bin/ls", NULL};
//     char *output_file = "output.txt";
//     execute_command_with_output_redirection(command, output_file);

//     return 0;
// }
