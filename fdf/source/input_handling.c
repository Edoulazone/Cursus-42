/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:00:57 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/15 16:19:12 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	escape_handle(int key, t_mlx_data *data)
{
	if (key == 53)
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
	return (0);
}
