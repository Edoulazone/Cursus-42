/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:57:33 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/10 17:04:50 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *get_points(char **argv)
{
    int     i;
    int     size;
    t_point *points;
    int     columns;

    i = 0;
    size = count_columns(argv[1]) * count_line(argv[1]);
    if (size == -1)
    {
        write(2, "Error: nothing to read\n", 23);
        exit(1);
    }
}
