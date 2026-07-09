/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_map_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:17:13 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 18:25:08 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "render.h"

// Get current posstion on the map
void	assign_map_pos(t_vector *vector, t_player *player)
{
	printf("player posx: %f, posy%f, dirx: %f, diry %f \n",
		player->pos_x, player->pos_y, player->dir_x, player->dir_y);
	vector->map_x = (int)player->pos_x;
	vector->map_y = (int)player->pos_y;
}
