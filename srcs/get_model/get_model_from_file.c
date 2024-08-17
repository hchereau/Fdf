/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/17 11:45:32 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_state	fill_model_from_line(char *line, int *model, int len_split_line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split == NULL || len_split_line != count_words(line, ' '))
		return (error);
	model = malloc(sizeof(int) * len_split_line);
	while (*split != NULL)
	{
		*model = ft_atoi(*split);
		++model;
		++split;
	}
}

static void	refresh_line(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
}

static t_state	fill_model(int **model, int size_split_line, char *line, int fd)
{
	t_state	is_valid_line;
	int		i;

	is_valid_line = success;
	i = 0;
	while (line != NULL && is_valid_line == success)
	{
		is_valid_line = fill_model_from_line(line, model[i], size_split_line);
		refresh_line(line, fd);
		++i;
	}
	if (is_valid_line == error)
	{
		ft_printf("fill_model: Invalid file\n");
		free_model(model);
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
	char	*line;
	t_state	state;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("get_model_from_file: Invalid file\n");
		return (error);
	}
	state = fill_model(model, count_words(line, ' '), line, fd);
	close(fd);
	return (state);
}

int	get_model_size(char *file)
{
	int			size;
	const int	fd = open(file, O_RDONLY);
	char		*line;

	size = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}
