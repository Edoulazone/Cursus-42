/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:21:24 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:08:19 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*string_copy;

	length = ft_strlen(s);
	string_copy = (char *)malloc(sizeof(char) * (length + 1));
	if (!string_copy)
		return (NULL);
	ft_memcpy(string_copy, s, length);
	string_copy[length] = '\0';
	return (string_copy);
}
