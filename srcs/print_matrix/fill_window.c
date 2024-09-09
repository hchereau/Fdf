/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:32:16 by imback            #+#    #+#             */
/*   Updated: 2024/09/09 17:29:46 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_window(t_display *display)
{
	fill_image(display->matrix->points, display);
	mlx_put_image_to_window(display->p_mlx, display->p_win,
		display->img->img, 0, 0);
	mlx_key_hook(display->p_win, key_hook, display);
	mlx_hook(display->p_win, 17, 0, close_window, display);
	mlx_loop(display->p_mlx);
}
