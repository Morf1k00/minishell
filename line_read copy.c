/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:04:20 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/06 18:14:17 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void pars_cmd(char **line)
// {
//     // int i;
//     int w;
//     // int c;

//     w = 0;
//     // i = 0;
//     // c = 0;
//     while(line != NULL)
//     {
//         // if (line[w][c] == '|' || line[w][c] == '<' || line[w][c]== '>')
//         //     i++;
//         printf("%s\n\t", line[w]);
//         w++;
//     }
//     // printf("%i\n", i);
// }
static void free_arv(char **arv)
{
    int i;

    i = 0;
    while(arv[i])
    {
        free(arv[i]);
        i++;
    }
}


char **line_read(char *line)
{
    char    **arv;
    int     i;
    int     c;
    int     w;
    int     j;

    i = 0;
    w = 0;
    j = strlen(line) + 1;
    arv = malloc(sizeof(char*) * (j));
    //arv[j] = '\0';
    if (arv == NULL)
    {
        printf("error with alloc memory string\n");
        return (0);
    }
    //printf("%li\n", strlen(line) - 1);
    while(line[i] != '\0')
    {
        c = i;
        while(line[i] != '\0' && line[i] != '\t' && line[i] != ' ')
            i++;
        j = i - c;
        arv[w] = malloc(sizeof(char) * j + 1);
        if(arv[w] == NULL)
        {
            printf("error with alloc memory argument\n");
            free(arv);
            return (0);
        }
        strncpy(arv[w], &line[c], j);
        arv[w][j] = '\0';
        printf("arv[%d]: %s\n", w, arv[w]);
        while ((line[i] == ' ' || line[i] == '\t' ) && line[i] != '\0')
            i++;
        w++;
    }
    return(arv);
}

