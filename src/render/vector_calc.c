/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:50:56 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 14:11:21 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void assign_ray_dirs(t_vector *vector, t_player *player)
{
	double	p_dir_x;
	double	p_dir_y;
	double	p_plane_x;
	double	p_plane_y;
	
	p_dir_x = player->dir_x;
	p_dir_y = player->dir_y;
	p_plane_x = player->plane_x;
	p_plane_x = player->plane_y;
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
	vector->map_x = player->pos_x;
	vector->map_y = player->pos_y;
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
		vector->side_dist_x = (player->pos_x - vector->map_x + 1) * vector->delta_dist_x;
	}
	if (vector->ray_dir_y < 0)
	{
		vector->step_y = -1;
		vector->side_dist_y = (player->pos_y - vector->map_y) * vector->delta_dist_y;
	}
	else
	{
		vector->step_y = 1;
		vector->side_dist_y = (player->pos_y - vector->map_y + 1) * vector->delta_dist_y;
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