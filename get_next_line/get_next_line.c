/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:22:41 by eschmitz          #+#    #+#             */
/*   Updated: 2024/05/17 18:57:21 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	char		*buffer;

	if (BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(save);
		free(buffer);
		save = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_and_save(fd, save, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	save = ft_get_line(line);
	return (line);
}

char	*read_and_save(int fd, char *save, char *buffer)
{
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	while (!ft_strchr(save) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(save);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = 0;
		if (!save)
			save = ft_strdup("");
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer))
			break ;
	}
	return (save);
}

char	*ft_get_line(char *line_buff)
{
	int		i;
	char	*line;

	i = 0;
	while (line_buff[i] != '\0' && line_buff[i] != '\n')
		i++;
	if (line_buff[i] == 0 || line_buff[1] == 0)
		return (NULL);
	line = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	if (!line)
		return (NULL);
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	line_buff[i + 1] = 0;
	return (line);
}
