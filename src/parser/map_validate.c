/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:26:23 by msnizek           #+#    #+#             */
/*   Updated: 2026/06/30 20:26:23 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

int	map_validate(t_scene *scene)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = -1;
	while (++y < scene->map.map_height)
	{
		x = -1;
		while (++x < scene->map.map_width)
		{
			if (scene->map.map[y][x] != ' ' && scene->map.map[y][x] != '\0')
			{
				if (check_map_char(scene, x, y, &player_count) != ERR_OK)
					return (ERR_MAP);
			}
		}
	}
	if (player_count != 1)
		return (ERR_MAP);
	if (check_map_enclosure(scene) != ERR_OK)
		return (ERR_MAP);
	return (ERR_OK);
}
