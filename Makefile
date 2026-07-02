NAME = cub3D
CC = cc
# Production flags -----MAIN-----
#CFLAGS = -Iminilibx-linux -Iincludes -Imaster_lib_ft/includes -Wall -Wextra -Werror


# Debug Production flags
#CFLAGS = -Iminilibx-linux -Iincludes -Imaster_lib_ft/includes -Wall -Wextra -Werror -g -O0 -fsanitize=address
# Testing flags
#CFLAGS = -Iminilibx-linux -Iincludes -Imaster_lib_ft/includes
# Debug flags
CFLAGS = -Iminilibx-linux -Iincludes -Imaster_lib_ft/includes -g -O0 -fsanitize=address


LIBFT_DIR = master_lib_ft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_FLAGS = -lXext -lX11 -lm -lz
MLX = $(MLX_DIR)/libmlx.a


SRCS_RENDER = src/render
SRCS_PARSER = src/parser

SRCS = \
	src/main.c \
	$(SRCS_RENDER)/cleanup.c \
	$(SRCS_RENDER)/pixel_utils.c \
	$(SRCS_RENDER)/render_scene.c \
	$(SRCS_RENDER)/vector_dda.c \
	$(SRCS_RENDER)/vector_delta_dist.c \
	$(SRCS_RENDER)/vector_map_pos.c \
	$(SRCS_RENDER)/vector_perp_wall_dist.c \
	$(SRCS_RENDER)/vector_ray_dir.c \
	$(SRCS_RENDER)/vector_step_side_dist.c \
	$(SRCS_RENDER)/vector_wall_x.c \
	$(SRCS_RENDER)/vector_draw_start_end.c \
	$(SRCS_RENDER)/vector_line.c \
	$(SRCS_RENDER)/event_hooks.c \
	$(SRCS_RENDER)/textures_load.c \
	$(SRCS_RENDER)/textures_get.c \
	$(SRCS_RENDER)/player_movement.c \
	$(SRCS_PARSER)/parser.c


HEADERS = \
	includes/cub3d.h \
	includes/render.h \
	includes/parser.h

OBJS = $(SRCS:.c=.o)

# --- Rebuild if headers change ---
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(MLX_FLAGS) -o $(NAME)



clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
