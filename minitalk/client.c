/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:19:35 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/03 15:09:53 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
void	send(int pid, char *str)
{
	
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	
	if (argc == 3)
	{
		pid = argv[1];
		str = argv[2];
		send(pid, str);
	}
	return (0);
}