/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:15:49 by imback            #+#    #+#             */
/*   Updated: 2024/09/20 15:41:12 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_state	is_existing_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error);
	close(fd);
	return (success);
}

static bool	is_not_hide_fdf_file(char *file)
{
	const size_t	len = ft_strlen(file);


	if (strncmp(file + len - 5, "/.fdf", len) == 0)
	{
		ft_dprintf(STDERR_FILENO, "File %s is a hidden file\n", file);
		return (false);
	}
	return (true);
}

static t_state	is_fdf_file(char *file)
{
	int		len;
	t_state	state;

	state = success;
	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".fdf", len) != 0)
	{
		ft_dprintf(STDERR_FILENO, "File %s is not a .fdf file\n", file);
		state = error;
	}
	else if (is_not_hide_fdf_file(file) == false)
		state = error;
	return (state);
}

t_state	is_valid_file(char *file)
{
	t_state	state;

	state = success;
	if (file == NULL || is_existing_file(file) == error
		|| is_fdf_file(file) == error)
	{
		print_error(ERROR_FILE);
		state = error;
	}
	return (state);
}
