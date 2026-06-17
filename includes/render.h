/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:12:21 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 13:15:14 by advorace         ###   ########.fr       */
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
}	t_vector;

void	clean_up(t_scene *scene, int exit_status);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color);
void	put_scene_pixel(t_scene *scene, int x1, int y1);
int		render_scene(void *param);

// Vector calculations
void	assign_ray_dirs(t_vector *vector, t_player *player);
void	assign_delta_dists(t_vector *vector);
void	assign_map_pos(t_vector *vector, t_player *player);
void	assign_step_side_dist(t_vector *vector, t_player *player);

// Digital differential analyser
void	dda(t_vector *vector, char **map);
