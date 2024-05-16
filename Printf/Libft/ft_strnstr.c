/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:41:09 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:10:46 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t length)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i < length)
	{
		j = 0;
		while ((haystack[i + j]) == needle[j] && (i + j) < length)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
