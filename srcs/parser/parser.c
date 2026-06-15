/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:42 by advorace          #+#    #+#             */
/*   Updated: 2026/06/15 12:23:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_arguments(t_player *player, int argc, char *argv[])
{
	player->world_map.map = worldMap;
	player->world_map.map_height = mapHeight;
	player->world_map.map_widht = mapWidth;
	player->pos_x = 3;
	player->pos_y = 1;
	player->dir_x = 3;
	player->dir_y = 7;
	player->plane_x = 0;
	player->plane_y = 0.66;
}
