/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segments_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:07:50 by imback            #+#    #+#             */
/*   Updated: 2024/08/25 21:09:21 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	choose_color(int color_start, int color_end, float t)
{
	int		r;
	int		g;
	int		b;

	r = (int)((1 - t) * ((color_start >> 16) & 0xFF)
			+ t * ((color_end >> 16) & 0xFF));
	g = (int)((1 - t) * ((color_start >> 8) & 0xFF)
			+ t * ((color_end >> 8) & 0xFF));
	b = (int)((1 - t) * (color_start & 0xFF) + t * (color_end & 0xFF));
	return ((r << 16) | (g << 8) | b);
}
