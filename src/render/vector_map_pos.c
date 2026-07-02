/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_map_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:17:13 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 18:19:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "render.h"

void assign_map_pos(t_vector *vector, t_player *player)
{
	// Get current posstion on the map
	printf("player posx: %f, posy%f, dirx: %f, diry %f \n", player->pos_x, player->pos_y, player->dir_x, player->dir_y);
	vector->map_x = (int)player->pos_x;
	vector->map_y = (int)player->pos_y;
	//printf("vector, mapx: %d, mapy: %d\n", vector->map_x, vector->map_y);
}