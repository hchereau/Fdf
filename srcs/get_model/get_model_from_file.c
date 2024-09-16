/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:21:48 by imback            #+#    #+#             */
/*   Updated: 2024/09/16 15:05:10 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_state	fill_color_and_matrix(t_model *model, int i_matrix, int i_split,
	char *split)
{
	char		**split_color;

	split_color = ft_split(split, ',');
	if (split_color == NULL || count_words(split, ',') > 2)
	{
		ft_dprintf(STDERR_FILENO, "fill_color_and_matrix: Invalid file\n");
		free_strs(split_color);
		return (error);
	}
	model->matrix[i_matrix][i_split] = ft_atoi(split_color[0]);
	if (count_words(split, ',') == 2)
	{
		model->is_color_map = true;
		model->matrix[i_matrix][i_split] = ft_atoi(split_color[0]);
		model->color[i_matrix][i_split] = ft_atoi_base(split_color[1]
				+ 2, HEXA_BASE);
	}
	else
	{
		model->matrix[i_matrix][i_split] = ft_atoi(split_color[0]);
		model->color[i_matrix][i_split] = WHITE;
	}
	free_strs(split_color);
	return (success);
}

static t_state	fill_model_from_line(char **line, t_model *model,
		size_t len_split_line, int i_matrix)
{
	char		**split;
	size_t		i_split;
	t_state		state;

	i_split = 0;
	model->is_color_map = false;
	split = ft_split(*line, ' ');
	state = success;
	if (split == NULL || len_split_line != count_words(*line, ' '))
		return (error);
	model->matrix[i_matrix] = (int *)malloc(sizeof(int) * len_split_line);
	model->color[i_matrix] = (int *)malloc(sizeof(int) * len_split_line);
	if (model->matrix[i_matrix] == NULL || model->color[i_matrix] == NULL)
	{
		free_strs(split);
		return (error);
	}
	while (split[i_split] != NULL && state == success)
	{
		state = fill_color_and_matrix(model, i_matrix, i_split, split[i_split]);
		++i_split;
	}
	free_strs(split);
	return (state);
}

static void	refresh_line(char **line, int fd)
{
	free(*line);
	*line = get_next_line(fd);
}

static t_state	fill_model(t_model *model, int len_split_line,
	char **line, int fd)
{
	t_state		is_valid_line;
	size_t		i;

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
		ft_dprintf(STDERR_FILENO, "fill_model: Invalid file\n");
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
		ft_dprintf(STDERR_FILENO, "get_model_from_file: Invalid file\n");
		return (error);
	}
	model->rows = get_model_size(file);
	model->matrix = (int **)malloc(sizeof(int *) * model->rows);
	model->color = (int **)malloc(sizeof(int *) * model->rows);
	if (model->matrix == NULL || model->color == NULL)
	{
		ft_dprintf(STDERR_FILENO, "get_model_from_file: Malloc error\n");
		free(line);
		return (error);
	}
	model->cols = count_words(line, ' ');
	state = fill_model(model, model->cols, &line, fd);
	close(fd);
	return (state);
}
