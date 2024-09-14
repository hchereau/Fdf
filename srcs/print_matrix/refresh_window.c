/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:36:47 by imback            #+#    #+#             */
/*   Updated: 2024/09/14 16:12:02 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_clear128(t_display *display)
{
	char		*p;
	__uint128_t	*p128;
	int			bytes;
	int			dqwords;

	p128 = (__uint128_t *)display->img->addr;
	bytes = WINDOW_WIDTH * WINDOW_HEIGHT * 4;
	dqwords = bytes >> 4;
	while (dqwords--)
		*p128++ = 0;
	p = (char *)p128;
	bytes &= 15;
	while (bytes--)
		*p++ = 0;
}

void	refresh_window(t_display *display)
{
	img_clear128(display);
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
