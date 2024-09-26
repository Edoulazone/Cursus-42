/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:10:09 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/26 15:14:40 by eschmitz         ###   ########.fr       */
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
