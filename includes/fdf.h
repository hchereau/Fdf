/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:17:08 by imback            #+#    #+#             */
/*   Updated: 2024/09/14 15:39:18 by hucherea         ###   ########.fr       */
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
# include <X11/X.h>
# include "libft.h"
# include "mlx.h"
# include <sys/time.h>

# define ERROR_FILE ENOENT
# define END_GNL 0
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define YELLOW 0xFFFF00
# define ERROR_MAIN 1
# define DISTANCE 1
# define HEIGHT_DIST 1
# define ZOOM 1
# define ESC_KEY 65307
# define PLUS_KEY 65451
# define MINUS_KEY 65453
# define TAB_KEY_SIZE 11
# define Q_KEY 113
# define E_KEY 101
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define TRANSLATION 2
# define ANGLE_ROTATE 1
# define ANGLE_ROTATE_ISOMETRIC 0.1
# define ANGLE_ROTATE_HORIZONTAL 273
# define ANGLE_ROTATE_VERTICAL 0
# define ZOOOM 1
# define HEXA_BASE "0123456789ABCDEF"

typedef enum e_state {error = -1, success}			t_state;
typedef enum e_pressed {not_pressed = 0, pressed}	t_pressed;


typedef struct s_display	t_display;

typedef struct s_center
{
	double	y_max;
	double	x_max;
	double	y_min;
	double	x_min;
	double	x_center;
	double	y_center;
	double	x_offset;
	double	y_offset;
}	t_center;

typedef struct s_extremum
{
	int	min;
	int	max;
}	t_extremum;

typedef struct s_model
{
	int			**matrix;
	int			**color;
	size_t		rows;
	size_t		cols;
	t_extremum	*extremum;
	bool		is_color_map;
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
	int		x;
	int		y;
	double	z;
	int		color;
}	t_point;

typedef struct s_matrix
{
	t_point	**points;
	t_point	**cp_points;
	size_t	rows;
	size_t	cols;
}	t_matrix;

typedef struct s_key
{
	t_pressed	state;
	int		keycode;
	void	(*f)(t_display *);
}	t_key;

typedef struct s_display
{
	void			*p_mlx;
	void			*p_win;
	t_matrix		*matrix;
	t_img			*img;
	double			zoom;
	double			horizontal_angle;
	double			vertical_angle;
	double			isometric_angle;
	double			translation_x;
	double			translation_y;
	t_center		*center;
	bool			is_color_map;
	t_key			keys[TAB_KEY_SIZE];
	float			fps;
	struct timeval	last_time;
	int				frame_count;
}	t_display;


typedef struct s_segment
{
	double		dx;
	double		dy;
	double		sx;
	double		sy;
	double		err;
	double		e2;
	double		start_color;
	double		end_color;
	double		start_x;
	double		start_y;
}	t_segment;


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
int		close_window(t_display *display);
int		key_hook(t_display *display);
void	free_matrix(t_matrix *matrix);
void	free_cp_matrix(t_matrix *matrix);
t_point	**copy_points(t_point **points, int rows, int cols);
void	refresh_window(t_display *display);
void	events(t_display *display);
void	center_points(t_center *center, t_display *display);
void	add_zoom(t_display *display, t_center *center, size_t y, size_t x);
void	center(t_display *display);
void	isometric(t_display	*display, size_t y, size_t x);
void	draws_segments(t_point **points, t_display *display);
int		choose_color(int color_start, int color_end, float t);
void	horizontal_rotate(t_display *display, size_t y, size_t x);
void	vertical_rotate(t_display *display, size_t y, size_t x);
void	key_events(t_display *display);
void	x_translation_key(t_display *display);
void	y_translation_key(t_display *display);
int		get_color_from_height(int heigh, t_extremum *extremum);
void	get_color(t_matrix *matrix, t_model *model, size_t x, size_t y);
void	x_translation(t_display *display, size_t y, size_t x);
void	y_translation(t_display *display, size_t y, size_t x);
bool	is_good_zoom(t_display *display);
void	fix_zoom(t_display *display);
void	setup_points(t_display *display);
int		key_press(int keycode, t_display *display);
int		key_release(int keycode, t_display *display);
void	rotate_vertical_key(t_display *display);
void	rotate_horizontal_key(t_display *display);
void	zoom_key(t_display *display);
#endif
