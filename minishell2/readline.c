/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:48:31 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/02 16:01:27 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "unistd.h"
#include "stdlib.h"
#include <readline/readline.h>
#include <readline/history.h>

int main (int argc, char **argv)
{
    char *input;

    while(1)
    {
        input =  readline ("minishell: ");//readinng line in terminal 

        add_history(input);// save previous line in history terminalas and u can scroll all previouses line like in terminal shell
        if (strcmp(input, "exit") == 0)// compare line with exit and if its exist that progarm close
            exit (0);
        // free(input);
        printf("u write this text: %s\n", input);
        rl_on_new_line();//in normal case i dont understand what this command do
        // printf("\n");
        rl_replace_line("", 0);
        // printf("\t");
        // rl_replace_line(input, 0);
        // rl_redisplay();//repeat previous line which we write before
        free(input);
    }
    return(0);
}
