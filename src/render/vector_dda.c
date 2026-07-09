/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:41:41 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 18:10:40 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	dda(t_vector *vector, char **map)
{
	vector->hit = 0;
	while (vector->hit == 0)
	{
		if (vector->side_dist_x < vector->side_dist_y)
		{
			vector->side_dist_x += vector->delta_dist_x;
			vector->map_x += vector->step_x;
			vector->side = 0;
		}
		else
		{
			vector->side_dist_y += vector->delta_dist_y;
			vector->map_y += vector->step_y;
			vector->side = 1;
		}
		if (map[vector->map_y][vector->map_x] == '1')
			vector->hit = 1;
	}
}
