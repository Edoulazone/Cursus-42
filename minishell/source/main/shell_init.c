/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:33:50 by eschmitz          #+#    #+#             */
/*   Updated: 2024/10/02 15:27:32 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    incr_shell_level(t_shell *sh)
{
    t_list  *in_env;
    int     new_value;
    char    *new_value_str;

    in_env = env_var("SHLVL", sh->env);
    if (!in_env)
        return (add_new_env_var("SHLVL", "1", &(sh->env), sh));
    new_value = ft_atoi(value(in_env)) + 1;
    new_value_str = s_alloc(ft_itoa(new_value), PROMPT, sh);
    if (new_value < 0)
    	edit_env_value(in_env, "0", false, sh);
    else if (new_value > 1000)
    {
		
	}
}

void    init_shell(t_shell *sh, char **env)
{
    errno = 0;
    sh->in_main_process = true;
    sh->last_status = EXIT_SUCCESS;
    sh->allocated_pointers[ONLY_CHECK] = NULL;
    sh->allocated_pointers[SH] = NULL;
    sh->allocated_pointers[PROMPT] = NULL;
    sh->temporary_files = NULL;
    sh->env = int_env(env, sh);
    incr_shell_level(sh);
    sh->parsing_error = NULL;
}
