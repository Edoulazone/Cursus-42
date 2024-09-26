/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:50 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/26 15:19:05 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	*input;

	(void)argc;
	// enable_raw_mode();
	while (1)
	{
		write(1, "minishell> ", 11);
		input = read_input();
		parse_input(input, argv);
		if (argv[0] == NULL)
			continue ;
		if (strcmp(argv[0], "cd") == 0)
			ft_cd(argv);
		else if (strcmp(argv[0], "pwd") == 0)
			ft_pwd();
		else if (strcmp(argv[0], "echo") == 0)
			ft_echo(argv);
		else if (strcmp(argv[0], "exit") == 0)
			ft_exit();
		else
			execute_command(argv);
		free(input);
	}
	// disable_raw_mode();
	return (0);
}
