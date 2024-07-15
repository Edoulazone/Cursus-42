/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:35:28 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/15 14:35:02 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(void)
{
	perror("Error");
	exit(1);
}

void	exit_malloc(void)
{
	write(2, "Error while allocating memory\n", 30);
	exit(1);
}

void	window_error(void)
{
	write(2, "Error while crating a new window\n", 33);
}
