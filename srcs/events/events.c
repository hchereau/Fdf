/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:13:01 by imback            #+#    #+#             */
/*   Updated: 2024/08/21 16:03:24 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	events(t_display *display)
{
	free_matrix(display->matrix);
	display->matrix->points = copy_points(display->matrix->cp_points,
			display->matrix->rows, display->matrix->cols);
	add_zoom(display);
	center(display);
	isometric(display);
	refresh_window(display);
}
