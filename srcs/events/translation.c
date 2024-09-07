/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:43:12 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/07 11:06:50 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_translation(t_display *display, size_t y, size_t x)
{
	display->matrix->points[y][x].x += display->translation_x;
}

void	y_translation(t_display *display, size_t y, size_t x)
{
	display->matrix->points[y][x].y += display->translation_y;
}
