/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:56:21 by imback            #+#    #+#             */
/*   Updated: 2024/09/22 15:15:27 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_display(t_display *display)
{
	display->p_mlx = mlx_init();
	if (display->p_mlx == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Failed to initialize mlx\n");
		exit(ERROR_MAIN);
	}
	display->p_win = mlx_new_window(display->p_mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fdf");
	if (display->p_win == NULL)
	{
		free(display->p_mlx);
		ft_dprintf(STDERR_FILENO, "Failed to create window\n");
		exit(ERROR_MAIN);
	}
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
	display->keys[10].keycode = Q_KEY;
	display->keys[11].keycode = E_KEY;
	display->keys[12].keycode = ESC_KEY;
	display->keys[13].keycode = SPACE_KEY;
	display->keys[14].keycode = C_KEY;
	setup_tab_keys_vue(display);
}

void	setup_values(t_display *display)
{
	display->factor = 1;
	if (display->keys[15].state == not_pressed
		&& display->keys[16].state == not_pressed
		&& display->keys[17].state == not_pressed)
	{
		display->is_parallel = false;
		display->is_isometric = true;
		display->zoom = 0;
		display->z_power = 1.0 / display->factor;
	}
	display->horizontal_angle = ANGLE_ROTATE_HORIZONTAL / display->factor;
	display->vertical_angle = ANGLE_ROTATE_VERTICAL / display->factor;
	display->isometric_angle = M_PI / 6;
	display->translation_x = 0;
	display->translation_y = 0;
	display->z_rotate_angle = 0;
}

void	setup_mlx(t_display *display)
{
	setup_display(display);
	setup_img(display);
	setup_tab_keys(display);
	setup_values(display);
}
