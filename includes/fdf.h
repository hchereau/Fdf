/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imback <imback@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:17:08 by imback            #+#    #+#             */
/*   Updated: 2024/08/21 17:29:19 by imback           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define ERROR_FILE ENOENT
# define END_GNL 0


# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define WHITE 0xFFFFFF
# define ERROR_MAIN 1
# define DISTANCE 5
# define ZOOM 1
# define ESC_KEY 65307
# define PLUS_KEY 65451
# define MINUS_KEY 65453
# define Q_KEY 113
# define E_KEY 101
# define ANGLE_ROTATE 10


typedef enum e_state {error = -1, success}	t_state;

typedef struct s_center
{
	size_t	y_max;
	size_t	x_max;
	size_t	y_min;
	size_t	x_min;
	size_t	x_center;
	size_t	y_center;
	size_t	x_offset;
	size_t	y_offset;
}	t_center;

typedef struct s_model
{
	int		**matrix;
	size_t	rows;
	size_t	cols;
}	t_model;

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
	t_point	**cp_points;
	size_t		rows;
	size_t		cols;
}	t_matrix;

typedef struct s_display
{
	void		*p_mlx;
	void		*p_win;
	t_matrix	*matrix;
	t_img		*img;
	size_t		zoom;
	size_t		angle;
	t_center	*center;
}	t_display;

t_state	get_model(char *file, t_model *model);
t_state	is_valid_file(char *file);
t_state	get_model_from_file(char *file, t_model *model);
int		get_model_size(char *file);
void	free_model(t_model *model);
void	print_error(int signal);
t_state	get_matrix_from_model(t_matrix *matrix, t_model *model);
void	setup_mlx(t_display *display);
void	fill_window(t_display *display);
void	fill_image(t_point **points, t_display *display);
void	img_pix_put(t_img *img, int x, int y, int color);
void	print_matrix_with_mlx(t_display *display);
void	close_window(t_display *display);
int		key_hook(int keycode, t_display *display);
void	free_matrix(t_matrix *matrix);
void	free_cp_matrix(t_matrix *matrix);
t_point	**copy_points(t_point **points, int rows, int cols);
void	refresh_window(t_display *display);
void	events(t_display *display);
void	center_points(t_center *center, t_display *display);
void	add_zoom(t_display *display);
void	center(t_display *display);
void	isometric(t_display	*display);
#endif
