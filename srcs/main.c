/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:12:47 by imback            #+#    #+#             */
/*   Updated: 2024/08/18 23:58:52 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// void print_model(t_model *model)
// {
// 	int i, j;
// 	for (i = 0; i < model->rows; i++)
// 	{
// 		for (j = 0; j < 4; j++)
// 		{
// 			printf("%d ", model->matrix[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

int	main(int ac, char **av)
{
	t_model		model;
	t_matrix	matrix;

	if (ac != 2)
	{
		printf("Usage: %s <file>\n", av[0]);
		return (ERROR_MAIN);
	}
	if (get_model(av[1], &model) == success)
	{
		if (get_matrix_from_model(&matrix, &model) == success)
			print_model(&matrix);
		else
		{
			printf("Failed to get matrix from model\n");
			free_model(model.matrix, model.rows);
			return (ERROR_MAIN);
		}
		free_model(model.matrix, model.rows);
	}
	else
	{
		printf("Failed to load model from file: %s\n", av[1]);
		return (ERROR_MAIN);
	}
}

// int	main(int ac, char **av)
// {
// 	int	**model;

// 	if (get_model(av[1], model) == success)
// 		print_model(model);
// 	return (0);
// }