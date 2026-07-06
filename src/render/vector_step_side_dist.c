/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_step_side_dist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:17:41 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 15:37:35 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

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
