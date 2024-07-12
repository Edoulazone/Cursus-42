/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:24 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/10 18:46:39 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx_data	*data;
	t_point		*points;
	int			i;

	if (ac == 2)
	{
		points = parsing(argv);
		data = make_window();
		data->point = points;
		data->argv = argv;
		data->width = count_columns(argv);
		data->height = count_lines(argv);
		if (data->width == -1 && data->height == 0)
			closed_window(data);
		projection(points, data, argv);
		draw(data, points);
	}
	else
		ft_putendl("Usage: ./fdf <map_file>");
	return (0);
}
