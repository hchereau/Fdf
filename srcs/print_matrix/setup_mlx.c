/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:56:21 by imback            #+#    #+#             */
/*   Updated: 2024/09/14 15:50:12 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_display(t_display *display)
{
	display->p_mlx = mlx_init();
	display->p_win = mlx_new_window(display->p_mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fdf");
}

static void	setup_img(t_display *display)
{
	display->img = malloc(sizeof(t_img));
	display->img->img = mlx_new_image(display->p_mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	display->img->addr = mlx_get_data_addr(display->img->img,
			&display->img->bpp,
			&display->img->line_len, &display->img->endian);
}

static void	setup_tab_keys(t_display *display)
{
	size_t	i;

	i = 0;
	while (i < TAB_KEY_SIZE)
	{
		display->keys[i].state = not_pressed;
		i++;
	}
	display->keys[0].keycode = PLUS_KEY;
	display->keys[1].keycode = MINUS_KEY;
	display->keys[2].keycode = W_KEY;
	display->keys[3].keycode = S_KEY;
	display->keys[4].keycode = D_KEY;
	display->keys[5].keycode = A_KEY;
	display->keys[6].keycode = UP_KEY;
	display->keys[7].keycode = DOWN_KEY;
	display->keys[8].keycode = RIGHT_KEY;
	display->keys[9].keycode = LEFT_KEY;
	display->keys[10].keycode = ESC_KEY;
}

static void	setup_values(t_display *display)
{

	display->zoom = 0;
	display->horizontal_angle = ANGLE_ROTATE_HORIZONTAL;
	display->vertical_angle = ANGLE_ROTATE_VERTICAL;
	display->isometric_angle = M_PI / 6;
	display->translation_x = 0;
	display->translation_y = 0;
	setup_tab_keys(display);
}



void	setup_mlx(t_display *display)
{
	setup_display(display);
	setup_img(display);
	setup_values(display);
}
