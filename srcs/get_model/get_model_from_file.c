/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:48 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 14:03:56 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_state	fill_model_from_line(char **line, t_model *model,
		size_t len_split_line, int i_matrix)
{
	char		**split;
	size_t		i_split;

	i_split = 0;
	split = ft_split(*line, ' ');
	if (split == NULL || len_split_line != count_words(*line, ' '))
		return (error);
	model->matrix[i_matrix] = (int *)malloc(sizeof(int) * len_split_line);
	if (model->matrix[i_matrix] == NULL)
	{
		free_strs(split);
		return (error);
	}
	while (split[i_split] != NULL)
	{
		model->matrix[i_matrix][i_split] = ft_atoi(split[i_split]);
		++i_split;
	}
	free_strs(split);
	return (success);
}

static void	refresh_line(char **line, int fd)
{
	free(*line);
	*line = get_next_line(fd);
}

static t_state	fill_model(t_model *model, int len_split_line,
	char **line, int fd)
{
	t_state	is_valid_line;
	int		i;

	is_valid_line = success;
	i = 0;
	while (*line != NULL && is_valid_line == success && i < model->rows)
	{
		is_valid_line = fill_model_from_line(line,
				model, len_split_line, i);
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

t_state	get_model_from_file(char *file, t_model *model)
{
	const int	fd = open(file, O_RDONLY);
	char		*line;
	t_state		state;

	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("get_model_from_file: Invalid file\n");
		return (error);
	}
	model->rows = get_model_size(file);
	model->matrix = (int **)malloc(sizeof(int *) * model->rows);
	if (model->matrix == NULL)
	{
		ft_printf("get_model_from_file: Malloc error\n");
		free(line);
		return (error);
	}
	model->cols = count_words(line, ' ');
	state = fill_model(model, model->cols, &line, fd);
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
	free(line);
	return (size);
}
