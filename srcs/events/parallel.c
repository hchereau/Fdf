/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:37:40 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/17 10:35:04 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel(t_display *display, size_t y, size_t x)
{
	display->matrix->points[y][x].x = display->matrix->points[y][x].x
		+ WINDOW_WIDTH / 2;
	display->matrix->points[y][x].y = display->matrix->points[y][x].y
		+ WINDOW_HEIGHT / 2;
}
