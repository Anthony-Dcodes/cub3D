/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:42 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 18:25:55 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	parse_arguments(t_scene *scene, int argc, char *argv[])
{
	static char *worldMap[] = {
    "        1111111111111111111111111",
	"        1000000000110000000000001",
	"        1011000001110000000000001",
	"        1001000000000000000000001",
	"111111111011000001110000000000001",
	"100000000011000001110111111111111",
	"11110111111111011100000010001    ",
	"11110111111111011101010010001    ",
	"11000000110101011100000010001    ",
	"10000000000000001100000010001    ",
	"10000000000000001101010010001    ",
	"1100000111010101111101111000111  ",
	"11110111 1110101 101111010001    ",
	"11111111 1111111 111111111111    "
	};
	
	
	// Starting index: 2,1
	// DIR = SOUTH
	scene->map.map = worldMap;
	scene->map.map_height = 14;
	scene->map.map_width = 33;
	scene->win_h = SCREEN_HEIGHT;
	scene->win_w= SCREEN_WIDTH;
	scene->player.pos_x = 9.5;
	scene->player.pos_y = 1.5;
	scene->player.dir_x = 0;
	scene->player.dir_y = 1;
	scene->player.plane_x = 0.66;
	scene->player.plane_y = 0;
	scene->floor_color = YELLOW;
	scene->ceiling_color = WHITE;
}
