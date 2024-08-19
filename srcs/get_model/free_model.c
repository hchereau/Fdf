/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:17:51 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 16:19:29 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->points[i]);
		i++;
	}
	free(matrix->points);
}

void	free_model(t_model *model)
{
	int	i;

	i = 0;
	while (i < model->rows)
	{
		free(model->matrix[i]);
		i++;
	}
	free(model->matrix);
}
