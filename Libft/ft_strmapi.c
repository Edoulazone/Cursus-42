/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:43:06 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:10:09 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	i;
	size_t	length;

	length = ft_strlen(s);
	string = (char *) malloc(length + 1);
	if (!string)
		return (NULL);
	i = -1;
	while ((++i) < length)
		string[i] = f(i, s[i]);
	string[i] = '\0';
	return (string);
}
