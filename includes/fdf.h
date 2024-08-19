/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:17:08 by imback            #+#    #+#             */
/*   Updated: 2024/08/19 09:42:51 by imback           ###   ########.fr       */
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

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define WHITE 0xFFFFFF
# define ERROR_MAIN 1
# define DISTANCE 10


typedef enum e_state {error = -1, success}	t_state;

typedef struct s_model
{
	int		**matrix;
	int		rows;
	int		cols;
}	t_model;

typedef struct s_display
{
	void	*p_mlx;
	void	*p_win;
}	t_display;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_matrix
{
	t_point	**points;
	int		rows;
	int		cols;
}	t_matrix;

t_state	get_model(char *file, t_model *model);
t_state	is_valid_file(char *file);
t_state	get_model_from_file(char *file, t_model *model);
int		get_model_size(char *file);
void	free_model(int **matrix, int rows);
void	print_error(int signal);
t_state	print_matrix_with_mlx(t_matrix *matrix);
t_state	get_matrix_from_model(t_matrix *matrix, t_model *model);
void	setup_mlx(t_display *display, t_img *img);
t_state	print_matrix(t_matrix *matrix, t_display *display, t_img *img);
void	img_pix_put(t_img *img, int x, int y, int color);
t_state	print_matrix_with_mlx(t_matrix *matrix);
#endif
