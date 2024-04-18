/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:41:09 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 19:17:37 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char*)haystack);
	i = -1;
	while (haystack[++i] && i < n)
	{
		j = 0;
		while ((haystack[i +j]) == needle[j] && (i + j) < n)
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)haystack + i);
		}
	}
	return (NULL);
}