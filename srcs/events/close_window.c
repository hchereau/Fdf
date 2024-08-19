/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:21:25 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 17:03:07 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_display *display)
{
	free_matrix(display->matrix);
	mlx_destroy_window(display->p_mlx, display->p_win);
	mlx_destroy_display(display->p_mlx);
	free(display->p_mlx);
	exit(0);
}

/* besoin de free image mais j'ai aucune version propre qui me vient a
l'esprit pour l'instant*/