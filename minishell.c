/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/19 18:42:48 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
	(void)argc;
	(void)argv;
	init_path(env, env_shell);
	env_shell->path = get_pathm(env_shell->env_paths);
}

void	print_list(t_vars **lst)
{
	t_vars	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("info: %s\ttype: %d\tlength: %d\n", tmp->token, tmp->type, tmp->length);
		tmp = tmp->next;
	}
}

// Helper function to check if a string is just spaces
int is_space_string(const char *str) {
    while (*str) {
        if (*str != ' ') return 0; // Not a space string
        str++;
    }
    return 1; // Only spaces
}

// Function to create a new array without " " strings
char **remove_space_strings(char **original) {
    int count = 0;
    int i;

    // Count non-space strings
    for (i = 0; original[i] != NULL; i++) {
        if (!is_space_string(original[i])) {
            count++;
        }
    }

    // Allocate memory for new array
    char **new_array = malloc(sizeof(char *) * (count + 1)); // +1 for NULL terminator
    if (!new_array) return NULL; // Memory allocation failed

    // Copy non-space strings to new array
    int j = 0;
    for (i = 0; original[i] != NULL; i++) {
        if (!is_space_string(original[i])) {
            new_array[j++] = strdup(original[i]); // Copy string
        }
    }
    new_array[j] = NULL; // NULL terminate the array

    return new_array;
}

int main(int argc, char **argv, char **env)
{
    char *input;
    char **line;
    t_env_path *env_shell;
    t_vars *list;

    list = NULL;
    env_shell = malloc(sizeof(t_env_path));
    init_arg(argc, argv, env, env_shell);
    start_shell(env_shell);
    while (1)
    {
        input = readline("minishell: ");
        if (!input)
        {
            free(input);
            break;
        }
        add_history(input);
        line = split_arg(input);
        env_shell->last = close_quote(line);
        if (env_shell->last == 0)
        {   
            lexer(line, env_shell);
			char **new_arv = remove_space_strings(env_shell->pipes->arv);
        // Free the original env_shell->pipes->arv array and its strings
        for (int i = 0; env_shell->pipes->arv[i]; i++)
            free(env_shell->pipes->arv[i]);
        free(env_shell->pipes->arv);
        // Assign the new array without spaces
        env_shell->pipes->arv = new_arv;
            check_pipe_line(env_shell);
            create_list(&list, env_shell->pipes->arv, env_shell);
        }   
        else
            exit_file(list, env_shell);
		// for (int i = 0; env_shell->pipes->arv[i]; i++)
		// 	printf("arv[%d]: %s\n", i, env_shell->pipes->arv[i]);
		execom(list, env_shell);
        ft_listclear(&list);
        free(input);
    }
    return 0;
}
