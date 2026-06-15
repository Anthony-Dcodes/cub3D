/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:42 by advorace          #+#    #+#             */
/*   Updated: 2026/06/15 14:19:34 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_arguments(t_player *player, int argc, char *argv[])
{
	char *worldMap[] = {
    "11111111",
    "10000101",
    "10000001",
    "10101101",
    "10000011",
    "10111001",
    "10000011",
    "11111111",
	};
	player->world_map.map = worldMap;
	player->world_map.map_height = mapHeight;
	player->world_map.map_widht = mapWidth;
	player->mlx_struct.win_height = screenHeight;
	player->mlx_struct.win_width= screenWidth;
	player->pos_x = 3;
	player->pos_y = 1;
	player->dir_x = 3;
	player->dir_y = 7;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->mlx_struct.i_line_length = 0;
}
