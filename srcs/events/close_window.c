/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:21:25 by imback            #+#    #+#             */
/*   Updated: 2024/08/21 14:20:31 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_display(t_display *display)
{
	free_matrix(display->matrix);
	free_cp_matrix(display->matrix);
	// free(display->matrix);
	free(display->p_mlx);
	free(display->img->img);
	free(display->img);
}


void	close_window(t_display *display)
{
	mlx_destroy_window(display->p_mlx, display->p_win);
	mlx_destroy_display(display->p_mlx);
	free_display(display);
	exit(0);
}
