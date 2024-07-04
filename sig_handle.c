/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:48:37 by debizhan          #+#    #+#             */
/*   Updated: 2024/07/04 15:03:25 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// void	sig_handle(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 		ft_putstr_fd("minishell > ", STDIN_FILENO);
// 	}
// }

// void	sig_handle_child(int sig)
// {
// 	if (sig == SIGQUIT)
// 	{
// 		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
// 	}
// 	if (sig == SIGINT)
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// }

// void	heredoc_sig_handle(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// }

// void handle_sigint(int sig)
// {
//     (void)sig;
//     write(STDOUT_FILENO, "\nminishell: ", 12);
// }

// void handle_sigquit(int sig)
// {
//     (void)sig;
// }

// void setup_signal_handlers(void)
// {
//     signal(SIGINT, handle_sigint);
//     signal(SIGQUIT, handle_sigquit);
// }

void    setup_signal_handlers(void)
{
    signal(SIGINT, handle_sigint);    
    signal(SIGQUIT, handle_sigquit);
}
void    handle_sigint(int sig)
{
    (void)sig;    
    write(STDOUT_FILENO, "\nminishell: ", 12);
}
void    handle_sigquit(int sig)
{
    (void)sig;
}