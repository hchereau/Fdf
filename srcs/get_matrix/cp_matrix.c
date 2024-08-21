/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:29:42 by imback            #+#    #+#             */
/*   Updated: 2024/08/21 09:29:54 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**copy_points(t_point **points, int rows, int cols)
{
	t_point	**cp_points;
	int		i;
	int		j;

	cp_points = (t_point **)malloc(sizeof(t_point *) * rows);
	if (!cp_points)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		cp_points[i] = (t_point *)malloc(sizeof(t_point) * cols);
		if (!cp_points[i])
			return (NULL);
		j = 0;
		while (j < cols)
		{
			cp_points[i][j] = points[i][j];
			j++;
		}
		i++;
	}
	return (cp_points);
}