/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:18:31 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:49:51 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	new_string_indent;
	size_t	s_indent;
	char	*new_string;

	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	new_string_indent = 0;
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !new_string)
		return (NULL);
	s_indent = start;
	while (s_indent < ft_strlen(s) && new_string_indent < len)
		new_string[new_string_indent++] = s[s_indent++];
	new_string[new_string_indent] = '\0';
	return (new_string);
}
