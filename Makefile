NAME = cub3D
CC = CC
CFLAGS = -Iminilibx-linx -Iincludes -Imaster_lib_ft/includes -Wall -Wextra -Werror

LIBFT_DIR = master_lib_ft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_FLAGS = -lXext -lX11 -lm -lz
MLX = $(MLX_DIR)/libmlx.a


SRCS_RENDER = src/render

SRCS = \
	src/main.c \
	$(SRCS_RENDER)/clenup.c \
	$(SRCS_RENDER)/pixel_utils.c \
	$(SRCS_RENDER)/render_scene.c


HEADERS = \
	includes/cub3d.h \
	includes/render.h \
	includes/parser.h

OBJC = $(SRCS:.c=.o)

# --- Rebuild if headers change ---
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME) $(LIBFT) $(MLX)

$(LIBFT)
	$(MAKE) -C (LIBFT_DIR)

$(MLX)
	$(MAKE) -C (MLX_DIR)

$(NAME): $(OBJC) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJC) $(MLX) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJC)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
