/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:10:09 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/26 16:50:10 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	auto_complete(char *input)
{
	struct dirent	*dp;
	DIR				*dir;

	dir = opendir(".");
	if (dir == NULL)
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		if (strncmp(dp->d_name, input, strlen(input)) == 0)
			printf("%s\n", dp->d_name);
	}
	closedir(dir);
}

void	enable_raw_mode()
{
	struct termios	termios_p;

	tcgetattr(STDIN_FILENO, &termios_p);
	termios_p.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_p);
}

void	disable_raw_mode()
{
	struct termios	termios_p;

	tcgetattr(STDIN_FILENO, &termios_p);
	termios_p.c_lflag |= ICANON | ECHO;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_p);
}
