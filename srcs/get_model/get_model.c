/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:16 by imback            #+#    #+#             */
/*   Updated: 2024/09/21 16:38:03 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_state	get_model(char *file, t_model *model)
{
	int	state;

	state = error;
	if (is_valid_file(file) == success)
	{
		if (get_model_from_file(file, model) == success)
		{
			state = success;
		}
		else
		{
			if (model->matrix != NULL)
				free_matrix(model->matrix);
			if (model->color != NULL)
				free_matrix(model->color);
			ft_dprintf(STDERR_FILENO,
				"Failed to get model from file: %s\n", file);
		}
	}
	return (state);
}
