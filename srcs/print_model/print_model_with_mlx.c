/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:57 by imback            #+#    #+#             */
/*   Updated: 2024/08/18 19:25:39 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_state	print_model_with_mlx(t_model *model)
{
	t_display	display;
	t_img		img;

	setup_mlx(&display, &img);
	print_model(model, &display, &img);
}