/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:29:42 by imback            #+#    #+#             */
/*   Updated: 2024/09/21 16:39:13 by hucherea         ###   ########.fr       */
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
		{
			free(cp_points);
			return (NULL);
		}
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
