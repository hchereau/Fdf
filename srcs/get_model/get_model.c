/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:16 by imback            #+#    #+#             */
/*   Updated: 2024/08/14 17:08:13 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_state	get_model(char *file, int **model)
{
	int	state;

	state = error;
	if (is_valid_file(file) == success)
	{
		if (get_model_from_file(file, model) == success)
		{
			state = success;
		}
	}
	return (state);


}
