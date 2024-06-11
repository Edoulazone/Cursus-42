/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:43:18 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 18:43:19 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bzero1(void *str, size_t n)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = (unsigned char *)str;
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
}

void	*ft_calloc1(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size && count > UINT_MAX / size)
		return (NULL);
	i = size * count;
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	ft_bzero1(ptr, i);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*my_ft_strjoin(char *my_stash, char *buffer)
{
	int		i;
	int		j;
	char	*result;

	if (!my_stash)
		my_stash = ft_calloc1(1, sizeof(char));
	if (!my_stash || !buffer)
		return (free(my_stash), NULL);
	j = 0;
	i = 0;
	result = ft_calloc1(ft_strlen(my_stash) + 
			ft_strlen(buffer) + 1, sizeof(char));
	if (!result)
		return (free(my_stash), NULL);
	while (my_stash[i])
		result[j++] = my_stash[i++];
	i = 0;
	while (buffer[i])
		result[j++] = buffer[i++];
	result[j++] = ' ';
	result[j] = '\0';
	free(my_stash);
	return (result);
}