/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:04:20 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/08 17:09:57 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// , t_line data
char **line_read(char *line)
{
    char    **arv;
    int     i;
    int     c;
    int     w;
    int     j;

    i = 0;
    w = 0;
    arv = malloc(sizeof(char*) * strlen(line) + 1);
    if (arv == NULL)
        printf("error with alloc memory string\n");
    while(line[i] != '\0')
    {
        c = i;
        while(line[i] != '\0' && line[i] != '\t' && line[i] != ' ')
            i++;
        j = i - c;
        arv[w] = malloc(sizeof(char) * j + 1);
        if(arv[w] == NULL)
            printf("error with alloc memory argument\n");
        strncpy(arv[w], &line[c], j);
        arv[w][j] = '\0';
        //printf("arv[%d]: %s\n", w, arv[w]);
        while ((line[i] == ' ' || line[i] == '\t' ) && line[i] != '\0')
            i++;
        w++;
    }
    // data.arg_c = w;
    // data.line_trim = strdup(arv);
    //split_arg(data);
    return(arv);
}

// void line_init()
// {
//     char *input;
//     t_line data;

//     input = readline("minishell: ");
//     add_history(input);
//     data.line_trim = line_read(input, data);
// }