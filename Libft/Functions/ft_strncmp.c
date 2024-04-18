/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:41:06 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 19:06:58 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	i = 0;
	if (n == 0)
		return (0);
	while (string_1[i] == string_2[i] && string_1[i] && string_2[i])
		i++;
	return (string_1[i] - string_2[i]);
}