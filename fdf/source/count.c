/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:32:10 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/15 18:23:41 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	number_words(char const *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != '\0')
			count++;
		while (s[index] != c && s[index])
			index++;
	}
	return (count);
}

int	count_columns(char *file_name)
{
	int		count;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
		exit_error();
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	count = number_words(line, ' ');
	if (*(ft_strrchr(line, ' ') + 1) == '\n')
		count--;
	free(line);
	close(fd);
	return (count);
}

int	count_lines(char *file_name)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
		exit_error();
	line = get_next_line(fd);
	while (line)
	{
		if (line)
			free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	count_number(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (ft_strncmp(array[i], "\n", 1) == 0)
			break ;
	}
	return (i);
}
