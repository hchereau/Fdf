/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_from_model.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:34:12 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 09:17:32 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_state	init_matrix(t_matrix *matrix, t_model *model)
{
	matrix->rows = model->rows;
	matrix->cols = model->cols;
	matrix->points = (t_point **)malloc(sizeof(t_point *) * model->rows);
	if (matrix->points == NULL)
		return (error);
	return (success);
}


static t_state	add_points(t_matrix *matrix, t_model *model)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < model->rows)
	{
		x = 0;
		matrix->points[y] = (t_point *)malloc(sizeof(t_point) * model->cols);
		if (matrix->points[y] == NULL)
			return (error);
		while (x < model->cols)
		{
			matrix->points[y][x].x = DISTANCE * x;
			matrix->points[y][x].y = DISTANCE * y;
			matrix->points[y][x].z = model->matrix[y][x];
			matrix->points[y][x].color = WHITE;
			++x;
		}
		++y;
	}
	return (success);
}

t_state	get_matrix_from_model(t_matrix *matrix, t_model *model)
{
	t_state	state;

	state = error;
	if (init_matrix(matrix, model) == success)
	{
		if (add_points(matrix, model) == success)
		{
			state = success;
		}
	}
	return (state);
}
