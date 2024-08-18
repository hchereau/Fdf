NAME := fdf

### LIBFT #####################################################################

LIBFT_FOLDER := libft/

LIBFT := $(LIBFT_FOLDER)/libft.a

### MINILIBX ##################################################################

MINILIBX_FOLDER := minilibx/
LIB_MLX := $(MINILIBX_FOLDER)/libmlx.a

### SRCS ######################################################################

PATH_SRCS += srcs
PATH_SRCS += srcs/get_model
PATH_SRCS += srcs/get_matrix

# srcs

SRCS += main.c
SRCS += error_state.c

# srcs/get_model

SRCS += get_model.c
SRCS += get_model_from_file.c
SRCS += is_valid_file.c
SRCS += free_model.c

# srcs/get_matrix

SRCS += get_matrix_from_model.c

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

### LINKING ####################################################################

LINKS += -Lmlx-linux
LINKS += -L/usr/lib
LINKS += -1Xext
LINKS += -lX11
LINKS += -lm
LINKS += -lz
LINKS += -fPIE

### RULES ######################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(INCLUDES)

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADERS)
		@mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -O3

$(LIBFT):
	$(MAKE) -C $(LIBFT_FOLDER)

clean:
	$(RM) -r $(PATH_OBJS)
	$(MAKE) -C $(LIBFT_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_FOLDER) fclean

re: fclean all

.PHONY: all clean fclean re
