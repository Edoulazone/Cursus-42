/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:32:18 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/10 18:44:14 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_point *points, t_mlx_data *data, char **argv)
{
	int		i;

	i = -1;
	while (points[++i].x != -1)
	{
		points[i].projected_x = (points[i].x - points[i].y) * (sqrt(3) / 2);
		points[i].projected_y = ((points[i].x + points[i].y) / 2) - points[i].z;
		points[i].projected_x += data->width / 2;
		points[i].projected_y += data->height / 2;
	}
}
