/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:50:56 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 17:13:10 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include <math.h>
#include <stdio.h>

void assign_ray_dirs(t_vector *vector, t_player *player)
{
	double	p_dir_x;
	double	p_dir_y;
	double	p_plane_x;
	double	p_plane_y;

	p_dir_x = player->dir_x;
	p_dir_y = player->dir_y;
	p_plane_x = player->plane_x;
	p_plane_y = player->plane_y;
	vector->ray_dir_x = p_dir_x + p_plane_x * vector->camera_x;
	vector->ray_dir_y = p_dir_y + p_plane_y * vector->camera_x;
}

void assign_delta_dists(t_vector *vector)
{
	// For DDA only ratios not the absolute values are needed
	vector->delta_dist_x = fabs(1 / vector->ray_dir_x);
	vector->delta_dist_y = fabs(1 / vector->ray_dir_y);
}

void assign_map_pos(t_vector *vector, t_player *player)
{
	// Get current posstion on the map
	printf("player posx: %f, posy%f, dirx: %f, diry %f \n", player->pos_x, player->pos_y, player->dir_x, player->dir_y);
	vector->map_x = (int)player->pos_x;
	vector->map_y = (int)player->pos_y;
	//printf("vector, mapx: %d, mapy: %d\n", vector->map_x, vector->map_y);
}

void assign_step_side_dist(t_vector *vector, t_player *player)
{
	if (vector->ray_dir_x < 0)
	{
		vector->step_x = -1;
		vector->side_dist_x = (player->pos_x - vector->map_x) * vector->delta_dist_x;
	}
	else
	{
		vector->step_x = 1;
		vector->side_dist_x = (vector->map_x + 1 - player->pos_x) * vector->delta_dist_x;
	}
	if (vector->ray_dir_y < 0)
	{
		vector->step_y = -1;
		vector->side_dist_y = (player->pos_y - vector->map_y) * vector->delta_dist_y;
	}
	else
	{
		vector->step_y = 1;
		vector->side_dist_y = (vector->map_y + 1 - player->pos_y) * vector->delta_dist_y;
	}
}

void	assign_perp_wall_dist(t_vector *vector)
{
	if (vector->side == 0)
	{
		vector->perp_wall_dist = (vector->side_dist_x - vector->delta_dist_x);
	}
	else
	{
		vector->perp_wall_dist = (vector->side_dist_y - vector->delta_dist_y);
	}
}

void	assign_wall_x(t_vector *vector, t_scene *scene)
{
	if (vector->side == 0)                        // hit an E/W wall (vertical)
    	vector->wall_x = scene->player.pos_y + vector->perp_wall_dist * vector->ray_dir_y;
	else                                           // hit a N/S wall (horizontal)
    	vector->wall_x = scene->player.pos_x + vector->perp_wall_dist * vector->ray_dir_x;
	vector->wall_x -= floor(vector->wall_x);       // keep only the fractional part (0.0-1.0)
}
