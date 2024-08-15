/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/15 09:16:21 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	is_valid_size_line(char *line, int size)
{
	if (size != ft_strlen(line))
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

static void	refresh_line(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
}

static t_state	fill_model(int **model, int size_line, char *line, int fd)
{
	bool	is_valid_size;
	t_state	is_valid_line;

	is_valid_size = true;
	is_valid_line = success;
	while (line != NULL && is_valid_size == success && is_valid_line == success)
	{
		is_valid_size = is_valid_size_line(line, size_line);
		if (is_valid_size == true)
		{
			is_valid_line = fill_model_from_line(line, model);
			refresh_line(line, fd);
		}
	}
	if (is_valid_size == false || is_valid_line == error)
	{
		ft_printf("get_model_from_file: Invalid file\n");
		return (error);
	}
	else
	{
		return (success);
	}
}

t_state	get_model_from_file(char *file, int **model)
{
	int		fd;
	int		size_line;
	char	*line;
	t_state	state;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	size_line = ft_strlen(line);
	state = fill_model(model, size_line, line, fd);
	close(fd);
	return (state);
}
