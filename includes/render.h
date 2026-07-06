/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:12:21 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 18:11:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"

typedef struct s_vector
{
	double		camera_x;
	double		delta_dist_x;
	double		delta_dist_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		wall_x;
}	t_vector;

#define WHITE   0xFFFFFF
#define BLACK   0x000000
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF
#define GRAY    0x808080
#define ORANGE  0xFF8000

// Keys
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// Events
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define MOVE_SPEED 0.2
# define ROT_SPEED 0.1

// Cleanup
void	clean_up(t_scene *scene, int exit_status);
void	clean_up_textures(t_scene *scene);
void	error_message(int err);
void	error_render(int err);
void	error_parser(int err);

// Pixels / render
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color);
void	put_scene_pixel(t_scene *scene, int x1, int y1, t_vector *vector);
int		render_scene(void *param);

// Vector calculations
void	assign_ray_dirs(t_vector *vector, t_player *player);
void	assign_delta_dists(t_vector *vector);
void	assign_map_pos(t_vector *vector, t_player *player);
void	assign_step_side_dist(t_vector *vector, t_player *player);
void	assign_perp_wall_dist(t_vector *vector);
void	assign_wall_x(t_vector *vector, t_scene *scene);

// Vertical pixel line calculations
void	assign_line_h(t_vector *vector, int win_h);
void	assign_draw_start_end(t_vector *vector, int win_h);

// Digital differential analyser
void	dda(t_vector *vector, char **map);

// Event hooks
int		key_press_hook(int keycode, void	*param);
int		handle_window_close(void *param);
void	move_player(t_player *player, int keycode);
void	rotate_player(t_player *player, int keycode);

// Textures
int		load_textures_render(t_scene *scene);
int		load_texture_render(t_scene *scene, t_img *tex, char *path);
int		get_texture_color(t_img *tex, int x, int y);
int		get_wall_texture(t_vector *vector);
int		get_texture_xpos(t_scene *scene, t_vector *vector, int wall);
int		get_texture_ypos(t_scene *scene, t_vector *vector, int y1, int wall);

// Init
int		init_mlx_win(t_scene *scene);
void	init_mlx_hooks(t_scene *scene);
