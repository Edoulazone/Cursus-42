/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:43 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:05:30 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_string;
	size_t			i;

	i = 0;
	new_string = (void *)(unsigned char *)s;
	while (i < n)
	{
		if (new_string[i] == (unsigned char)c)
			return (new_string + i);
		i++;
	}
	return (NULL);
}
