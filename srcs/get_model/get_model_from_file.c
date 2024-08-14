/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/14 17:07:55 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	refresh_line(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
}

t_state	get_model_from_file(char *file, int **model)
{
	int		fd;
	char	*line;
	bool	is_valid_size;

	is_valid_size = true;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL && is_valid_size == true)
	{
		is_valid_size = is_valid_line(line);
		fill_line_in_model(line, model);
		refresh_line(line, fd);
	}
}
