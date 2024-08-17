/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/17 13:23:48 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_state	fill_model_from_line(char *line, int *model,
		size_t len_split_line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split == NULL || len_split_line != count_words(line, ' '))
		return (error);
	model = (int *)malloc(sizeof(int) * len_split_line);
	if (model == NULL)
	{
		free_strs(split);
		return (error);
	}
	while (*split != NULL)
	{
		*model = ft_atoi(*split);
		++model;
		++split;
	}
	// free_strs(split);
	return (success);
}

static void	refresh_line(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
}

static t_state	fill_model(t_model *model, int len_split_line,
	char *line, int fd)
{
	t_state	is_valid_line;
	int		i;

	is_valid_line = success;
	i = 0;
	while (line != NULL && is_valid_line == success && i < model->rows)
	{
		is_valid_line = fill_model_from_line(line,
				model->matrix[i], len_split_line);
		refresh_line(line, fd);
		++i;
	}
	if (is_valid_line == error)
	{
		ft_printf("fill_model: Invalid file\n");
		free_model(model->matrix, model->rows);
		return (error);
	}
	else
	{
		return (success);
	}
}

t_state	get_model_from_file(char *file, t_model *model)
{
	const int	fd = open(file, O_RDONLY);
	char		*line;
	t_state		state;

	line = get_next_line(fd);
	model->rows = get_model_size(file);
	if (line == NULL)
	{
		ft_printf("get_model_from_file: Invalid file\n");
		return (error);
	}
	model->matrix = (int **)malloc(sizeof(int *) * model->rows);
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
