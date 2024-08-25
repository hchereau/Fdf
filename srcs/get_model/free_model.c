/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:17:51 by imback            #+#    #+#             */
/*   Updated: 2024/08/25 14:55:22 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_matrix *matrix)
{
	size_t	i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->points[i]);
		i++;
	}
	free(matrix->points);
}

void	free_cp_matrix(t_matrix *matrix)
{
	size_t	i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->cp_points[i]);
		i++;
	}
	free(matrix->cp_points);
}

void	free_model(t_model *model)
{
	size_t	i;

	i = 0;
	while (i < model->rows)
	{
		free(model->matrix[i]);
		free(model->color[i]);
		i++;
	}
	free(model->matrix);
	free(model->color);
}
