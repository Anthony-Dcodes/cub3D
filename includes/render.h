/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:12:21 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 14:39:32 by advorace         ###   ########.fr       */
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

void	clean_up(t_scene *scene, int exit_status);
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

// Vertical pixel line calculations
void	assign_line_h(t_vector *vector, int win_h);
void	assign_draw_start_end(t_vector *vector, int win_h);

// Digital differential analyser
void	dda(t_vector *vector, char **map);
