/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:05:41 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/26 16:06:50 by eschmitz         ###   ########.fr       */
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

void	read_input(char *buffer)
{
	int		len;
	char	c;

	len = 0;
	while (1)
	{
		read(STDIN_FILENO, &c, 1);
		if (c == 9)
		{
			buffer[len] = '\0';
			auto_complete(buffer);
		}
		else if (c == 10)
		{
			buffer[len] = '\0';
			return ;
		}
		else
		{
			buffer[len] = c;
			len++;
			write(STDOUT_FILENO, &c, 1);
		}
	}
}
