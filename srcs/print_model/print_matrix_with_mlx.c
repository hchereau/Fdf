/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_model_with_mlx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:57 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 00:12:35 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_state	print_matrix_with_mlx(t_matrix *matrix)
{
	t_display	display;
	t_img		img;

	setup_mlx(&display, &img);
	print_matrix(matrix, &display, &img);
}