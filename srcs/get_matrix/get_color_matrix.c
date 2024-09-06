/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:43:45 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/06 14:44:42 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color_from_height(int heigh, t_extremum *extremum)
{
	if (heigh == extremum->min)
		return (GREEN);
	else if (heigh == extremum->max)
		return (RED);
	else
		return (YELLOW);
}

void	get_color(t_matrix *matrix, t_model *model, size_t x, size_t y)
{
	if (model->is_color_map == false)
	{
		matrix->points[y][x].color
			= get_color_from_height(model->matrix[y][x], model->extremum);
	}
	else
	{
		matrix->points[y][x].color = model->color[y][x];
	}
}
