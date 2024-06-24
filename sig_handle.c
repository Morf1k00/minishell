/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:48:37 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/28 16:48:48 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		ft_putstr_fd("minishell > ", STDIN_FILENO);
	}
}

void	sig_handle_child(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	}
	if (sig == SIGINT)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

void	heredoc_sig_handle(int sig)
{
	if (sig == SIGINT)
	{
		exit(EXIT_FAILURE);
	}
}
