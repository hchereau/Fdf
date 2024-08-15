/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:17:08 by imback            #+#    #+#             */
/*   Updated: 2024/08/15 09:15:55 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define ERROR_FILE ENOENT
# define END_GNL 0

typedef enum e_state{error = -1, success}	t_state;

t_state	get_model(char *file, int **model);
t_state	is_valid_file(char *file);
t_state	get_model_from_file(char *file, int **model);
t_state	fill_model_from_line(char *line, int **model);

#endif
