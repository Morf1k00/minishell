/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:12:28 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/19 17:27:04 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

int execute_pipe(t_env_path *data, char **arv, int num_commands) {
    int pipe_fd[2];
    int prev_fd = -1;
    pid_t pid;
    int status;
    int i = 0;
    int cmd_start = 0;

    for (int cmd_index = 0; cmd_index < num_commands; cmd_index++) {
        if (cmd_index < num_commands - 1) {
            if (pipe(pipe_fd) == -1) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }
        } else {
            pipe_fd[0] = -1;
            pipe_fd[1] = -1;
        }

        while (arv[i] && strcmp(arv[i], "|") != 0) {
            i++;
        }
        arv[i] = NULL;

        if ((pid = fork()) == 0) {
            if (prev_fd != -1) {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (pipe_fd[1] != -1) {
                dup2(pipe_fd[1], STDOUT_FILENO);
                close(pipe_fd[1]);
            }
            close(pipe_fd[0]);

            execvp(arv[cmd_start], &arv[cmd_start]);
            perror("execvp");
            exit(127);
        }

        if (prev_fd != -1) {
            close(prev_fd);
        }
        if (pipe_fd[1] != -1) {
            close(pipe_fd[1]);
        }
        prev_fd = pipe_fd[0];
        cmd_start = ++i;
    }

    while (wait(&status) > 0);

    if (WIFEXITED(status)) {
        data->pipes->count = WEXITSTATUS(status);
    }

    return 0;
}
