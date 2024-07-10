/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:11:41 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/10 16:06:30 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point project(int x, int y, t_fdf *fdf)
{
    t_point point;
    int z = fdf->map->matrix[y][x];

    point.x = (x - y) * cos(0.523599);
    point.y = (x + y) * sin(0.523599) - z;
    return point;
}

void draw_line(t_fdf *fdf, t_point start, t_point end)
{
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = start.x < end.x ? 1 : -1;
    int sy = start.y < end.y ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1)
	{
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, start.x, start.y, 0xFFFFFF);
        if (start.x == end.x && start.y == end.y)
            break;
        e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            start.x += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            start.y += sy;
        }
    }
}

void draw_map(t_fdf *fdf)
{
    int x;
    int y;

    y = 0;
    while (y < fdf->map->height)
	{
        x = 0;
        while (x < fdf->map->width)
		{
            if (x < fdf->map->width - 1)
                draw_line(fdf, project(x, y, fdf), project(x + 1, y, fdf));
            if (y < fdf->map->height - 1)
                draw_line(fdf, project(x, y, fdf), project(x, y + 1, fdf));
            x++;
        }
        y++;
    }
}
