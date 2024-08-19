/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:21:25 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 11:52:21 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	free_matrix(t_matrix *matrix)
// {
// 	int	i;

// 	i = 0;
// 	while (i < matrix->rows)
// 	{
// 		free(matrix->points[i]);
// 		i++;
// 	}
// 	free(matrix->points);
// }

void	close_window(t_display *display, t_matrix *matrix)
{
	(void)matrix;
	mlx_destroy_window(display->p_mlx, display->p_win);
	mlx_destroy_display(display->p_mlx);
	// free_matrix(matrix);
	exit(0);
}