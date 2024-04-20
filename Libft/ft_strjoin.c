/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:31:04 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/20 12:36:02 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		indent;
	int		length_s1;
	int		length_s2;
	char	*string;

	if (s1 && s2)
	{
		length_s1 = ft_strlen(s1);
		length_s2 = ft_strlen(s2);
		string = (char *)malloc(sizeof(char) * (length_s1 + length_s2 + 1));
		if (string == NULL)
			return (NULL);
		indent = -1;
		while (s1[++indent])
			string[indent] = s1[indent];
		indent = -1;
		while (s2[++indent])
			string[length_s1 + indent] = s2[indent];
		string[length_s1 + indent] = '\0';
		return (string);
	}
	return (NULL);
}
