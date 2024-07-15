/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:00:57 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/15 18:46:25 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	escape_handle(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_connection, data->image->image_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->point);
	free(data->mlx_connection);
	free(data->image);
	free(data);
	write(1, "The window got closed\n", 22);
	exit(1);
}

void	zoom_in(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while ((points)[i].x != -1)
	{
		(points)[i].projected_x *= 1.1;
		(points)[i].projected_y *= 1.1;
		(points)[i].projected_x -= 115;
		(points)[i].projected_y -= 40;
		i++;
	}
	mlx_destroy_image(data->mlx_connection, data->image->image_ptr);
	draw(data, points);
}

void	zoom_out(t_point *points, t_mlx_data *data)
{
	int	i;

	i = 0;
	while ((points)[i].x != -1)
	{
		(points)[i].projected_x *= 0.9;
		(points)[i].projected_y *= 0.9;
		(points)[i].projected_x += 115;
		(points)[i].projected_y += 40;
		i++;
	}
	mlx_destroy_image(data->mlx_connection, data->image->image_ptr);
	draw(data, points);
}

int	key_handle(int key, t_mlx_data *data)
{
	if (key == 53)
		escape_handle(data);
	else if (key == 69)
		zoom_in(data->point, data);
	else if (key == 78)
		zoom_out(data->point, data);
	else if (key == 123)
		translate_left(data->point, data);
	else if (key == 124)
		translate_right(data->point, data);
	else if (key == 126)
		translate_down(data->point, data);
	else if (key == 125)
		translate_up(data->point, data);
	else if (key == 7)
		rotation_x(data->point, data);
	return (0);
}
