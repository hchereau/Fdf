/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:12:47 by imback            #+#    #+#             */
/*   Updated: 2024/09/16 15:03:34 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_state	get_matrix(char *file, t_display *display)
{
	t_state		state;
	t_model		model;
	t_matrix	matrix_temp;

	state = error;
	if (get_model(file, &model) == success)
	{
		if (get_matrix_from_model(&matrix_temp, &model) == success)
		{
			display->matrix = &matrix_temp;
			state = success;
		}
		else
		{
			printf("Failed to get matrix from model\n");
		}
		free_model(&model);
	}
	else
	{
		printf("Failed to get model from file: %s\n", file);
	}
	return (state);
}

static bool	is_valid_argument_number(int ac, char *output)
{
	if (ac == 2)
		return (true);
	else
	{
		ft_dprintf(STDERR_FILENO, "Usage: %s <file>\n", output);
		return (false);
	}
}

int	main(int ac, char **av)
{
	t_display	display;
	int			state_main;

	state_main = ERROR_MAIN;
	if (is_valid_argument_number(ac, av[0]) == true)
	{
		if (get_matrix(av[1], &display) == success)
		{
			print_matrix_with_mlx(&display);
		}
	}
	return (state_main);
}
