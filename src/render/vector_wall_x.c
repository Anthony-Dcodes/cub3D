/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_wall_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:18:39 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 17:04:35 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include <math.h>

/*
	side == 0
		hit an E/W wall (vertical)
	side == 1
		hit a N/S wall (horizontal)
	keep only the fractional part (0.0-1.0)
*/

void	assign_wall_x(t_vector *vector, t_scene *scene)
{
	if (vector->side == 0)
		vector->wall_x = scene->player.pos_y + vector->perp_wall_dist * vector->ray_dir_y;
	else
		vector->wall_x = scene->player.pos_x + vector->perp_wall_dist * vector->ray_dir_x;
	vector->wall_x -= floor(vector->wall_x);
}
