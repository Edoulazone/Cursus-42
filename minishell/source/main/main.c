/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:50 by eschmitz          #+#    #+#             */
/*   Updated: 2024/10/02 14:29:46 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;
	int		status;

	(void)argv;
	if (argc != 1)
		exit(EXIT_FAILURE);
	init_shell(&sh, envp);
	status = act_shell(&sh);
	quit_shell(&sh, status);	
}
