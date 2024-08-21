/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix_with_mlx.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:57 by imback            #+#    #+#             */
/*   Updated: 2024/08/21 10:12:17 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_matrix_with_mlx(t_display *display)
{
	setup_mlx(display);
	display->matrix->cp_points = copy_points(display->matrix->points,
			display->matrix->rows,
			display->matrix->cols);
	fill_window(display);
}
