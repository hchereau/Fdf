/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:15:49 by imback            #+#    #+#             */
/*   Updated: 2024/09/16 17:17:52 by hucherea         ###   ########.fr       */
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

static t_state	is_fdf_file(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".fdf", strlen(file)) != 0)
	{
		ft_dprintf(STDERR_FILENO, "File %s is not a .fdf file\n", file);
		return (error);
	}
	return (success);
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
