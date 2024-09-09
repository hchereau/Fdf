/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:36:47 by imback            #+#    #+#             */
/*   Updated: 2024/09/09 15:13:16 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	refresh_window(t_display *display)
{
	mlx_destroy_image(display->p_mlx, display->img->img);
	display->img->img = mlx_new_image(display->p_mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (display->img->img == NULL)
	{
		close_window(display);
	}
	else
	{
		fill_image(display->matrix->points, display);
		display->img->addr = mlx_get_data_addr(display->img->img,
				&display->img->bpp, &display->img->line_len,
				&display->img->endian);
		mlx_put_image_to_window(display->p_mlx, display->p_win,
			display->img->img, 0, 0);
		free_matrix(display->matrix);
		display->matrix->points = copy_points(display->matrix->cp_points,
				display->matrix->rows, display->matrix->cols);
	}
}
