/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:04:20 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/06 18:30:50 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



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
    //printf("%i\n",w);
    return(arv);
}
