/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:05:41 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/26 14:53:49 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_input(char *input, char **argv)
{
	int	i;

	i = 0;
	argv[i] = strtok(input, " \n");
	while (argv[i++] != NULL)
		argv[i] = strtok(NULL, " \n");
}

char	*read_input(void)
{
	char	*input;
	size_t	buffer_size;

	buffer_size = 1024;
	input = (char *)malloc(sizeof(char) * buffer_size);
	if (!input)
	{
		write(2, "Allocation error\n", 17);
		exit(EXIT_FAILURE);
	}
	if (getline(&input, &buffer_size, stdin) == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	return (input);
}
