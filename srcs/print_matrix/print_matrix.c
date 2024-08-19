/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:32:16 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 11:43:10 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_row(t_point *points, int cols, t_img *img)
{
	int	x;

	x = 0;
	while (x < cols)
	{
		img_pix_put(img, points[x].x, points[x].y, points[x].color);
		++x;
	}
}

void	print_matrix(t_matrix *matrix, t_display *display, t_img *img)
{
	int	y;

	y = 0;
	while (y < matrix->rows)
	{
		print_row(matrix->points[y], matrix->cols, img);
		++y;
	}
	mlx_put_image_to_window(display->p_mlx, display->p_win, img->img, 0, 0);
	mlx_key_hook(display->p_win, key_hook, display);
	mlx_loop(display->p_mlx);
}
