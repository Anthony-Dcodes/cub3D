/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:42 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 10:18:24 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_arguments(t_scene *scene, int argc, char *argv[])
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
	// Starting index: 2,1
	// DIR = SOUTH
	scene->map.map = worldMap;
	scene->map.map_height = 8;
	scene->map.map_width = 8;
	scene->win_h = SCREEN_HEIGHT;
	scene->win_w= SCREEN_WIDTH;
	scene->player.pos_x = 1.5;
	scene->player.pos_y = 2.5;
	scene->player.dir_x = 0;
	scene->player.dir_y = 1;
	scene->player.plane_x = 0.66;
	scene->player.plane_y = 0;
}
