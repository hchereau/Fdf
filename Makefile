NAME := fdf

### LIBFT #####################################################################

LIBFT_FOLDER := libft/

LIBFT := $(LIBFT_FOLDER)/libft.a

### MINILIBX ##################################################################

MINILIBX_FOLDER := minilibx/
LIB_MLX := $(MINILIBX_FOLDER)/libmlx.a

### SRCS ######################################################################

PATH_SRCS := srcs

SRCS += main.c

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

CC := CC

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

$(NAME): $(LIBFT) $(LIB_MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIB_MLX) $(LINKS) $(INCLUDES)

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
