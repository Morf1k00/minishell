/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/06 17:39:21 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
    char *input;

    while(1)
    {
        char **line;
        input = readline("minishell: ");
        add_history(input);

        if (strcmp(input, "exit") == 0)
            exit(0);
        line = line_read(input);
        for (size_t i = 0; i < 3; i++)
        {
            printf("%s\n", line[i]);
        }
        
        free(input);
    }
}
