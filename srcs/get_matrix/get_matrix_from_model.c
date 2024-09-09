/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_from_model.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:34:12 by imback            #+#    #+#             */
/*   Updated: 2024/09/07 13:38:31 by hucherea         ###   ########.fr       */
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

void	get_extremum(t_model *model)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	model->extremum = (t_extremum *)malloc(sizeof(t_extremum));
	model->extremum->min = model->matrix[0][0];
	model->extremum->max = model->matrix[0][0];
	while (y < model->rows)
	{
		x = 0;
		while (x < model->cols)
		{
			if (model->matrix[y][x] < model->extremum->min)
				model->extremum->min = model->matrix[y][x];
			if (model->matrix[y][x] > model->extremum->max)
				model->extremum->max = model->matrix[y][x];
			++x;
		}
		++y;
	}
}

void	get_coordinat(t_matrix *matrix, t_model *model, size_t x, size_t y)
{
	double	multiplier_z;

	multiplier_z = DISTANCE;
	multiplier_z /= 10;
	matrix->points[y][x].x = DISTANCE * x;
	matrix->points[y][x].y = DISTANCE * y;
	matrix->points[y][x].z = model->matrix[y][x];
	matrix->points[y][x].z *= multiplier_z;
}

static t_state	add_points(t_matrix *matrix, t_model *model)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (model->is_color_map == false)
		get_extremum(model);
	while (y < model->rows)
	{
		x = 0;
		matrix->points[y] = (t_point *)malloc(sizeof(t_point) * model->cols);
		if (matrix->points[y] == NULL)
			return (error);
		while (x < model->cols)
		{
			get_coordinat(matrix, model, x, y);
			get_color(matrix, model, x, y);
			++x;
		}
		++y;
	}
	if (model->is_color_map == false)
		free(model->extremum);
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
