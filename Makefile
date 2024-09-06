NAME := fdf

### LIBFT #####################################################################

LIBFT_FOLDER := libft/

LIBFT := $(LIBFT_FOLDER)/libft.a

### MINILIBX ##################################################################

MINILIBX_FOLDER := minilibx-linux/
LIB_MLX := $(MINILIBX_FOLDER)/libmlx.a

### SRCS ######################################################################

PATH_SRCS += srcs
PATH_SRCS += srcs/get_model
PATH_SRCS += srcs/get_matrix
PATH_SRCS += srcs/print_matrix
PATH_SRCS += srcs/events/key_events
PATH_SRCS += srcs/events/segments
PATH_SRCS += srcs/events

# srcs

SRCS += main.c
SRCS += error_state.c

# srcs/get_model

SRCS += get_model.c
SRCS += get_model_from_file.c
SRCS += is_valid_file.c
SRCS += free_model.c
SRCS += get_model_size.c

# srcs/get_matrix

SRCS += get_matrix_from_model.c
SRCS += cp_matrix.c
SRCS += get_color_matrix.c

# srcs/print_matrix

SRCS += fill_window.c
SRCS += print_matrix_with_mlx.c
SRCS += setup_mlx.c
SRCS += img_pix_put.c
SRCS += refresh_window.c

# srcs/events/key_events

SRCS += key_events.c
SRCS += key_hook.c

# srcs/events

SRCS += close_window.c
SRCS += events.c
SRCS += center.c
SRCS += zoom.c
SRCS += isometric.c
SRCS += rotate.c

# srcs/events/segments

SRCS += segment.c
SRCS += segments_color.c

vpath %.c $(PATH_SRCS)

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

### HEADERS ###################################################################

INCLUDES_FDF := includes/
INCLUDES_LIBFT := $(LIBFT_FOLDER)/includes/
INCLUDES_MLX := $(MINILIBX_FOLDER)/
INCLUDES += -I $(INCLUDES_FDF)
INCLUDES += -I $(INCLUDES_LIBFT)
INCLUDES += -I $(INCLUDES_MLX)

HEADERS += $(INCLUDES_FDF)fdf.h

### COMPILATION ################################################################

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -O2

### LINKING ####################################################################

LINKS += -Lmlx-linux
LINKS += -L/usr/lib
LINKS += -lXext
LINKS += -lX11
LINKS += -lm
LINKS += -lz
LINKS += -fPIE

### RULES ######################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(LIB_MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIB_MLX) $(INCLUDES) $(LINKS)

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADERS)
		@mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -O3

$(LIBFT):
	$(MAKE) -C $(LIBFT_FOLDER)

$(LIB_MLX):
	$(MAKE) -C $(MINILIBX_FOLDER)

clean:
	$(RM) -r $(PATH_OBJS)
	$(MAKE) -C $(LIBFT_FOLDER) clean
	$(MAKE) -C $(MINILIBX_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all clean fclean re
