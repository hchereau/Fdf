/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:15:49 by imback            #+#    #+#             */
/*   Updated: 2024/08/31 17:52:33 by imback           ###   ########.fr       */
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

t_state	is_valid_file(char *file)
{
	t_state	state;

	state = success;
	if (file == NULL || is_existing_file(file) == error)
	{
		print_error(ERROR_FILE);
		state = error;
	}
	return (state);
}
