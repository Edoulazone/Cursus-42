/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:41:00 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 13:57:02 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *destination, const char *source, size_t destination_size)
{
	size_t	i;

	i = -1;
	if (!destination || !source)
		return (0);
	while (source[++i] && i < destination_size - 1)
		destination[i] = source[i];
	if (destination_size > 0)
	{
		destination[i] = '\0';
		i++;
	}
	return (ft_strlen(source));
}