/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:57 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 13:55:11 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t destination_size)
{
	size_t	destination_length;
	size_t	index;
	size_t	i;

	destination_length = ft_strlen(destination);
	index = 0;
	while (destination[index])
		index++;
	i = 0;
	while (source[i] && (i + index + 1) < (destination_size))
	{
		destination[index + i] = source[i];
		i++;
	}
	if (i < destination_size)
		destination[index + i] = '\0';
	if (destination_size <= destination_length)
		return (ft_strlen(source) + destination_size);
	else
		return (ft_strlen(source) + destination_length);
}