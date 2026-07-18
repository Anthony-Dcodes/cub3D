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

int	check_dup_and_col(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (ft_strncmp(scene->tex_paths[i], scene->tex_paths[j],
				ft_strlen(scene->tex_paths[i]) + 1) == 0)
			return (ERR_DUP_TEX_PATH);
			j++;
		}
		i++;
	}
	if (scene->floor_color == scene->ceiling_color)
		return (ERR_DUP_COLOR);
	return (ERR_OK);
}

int	map_validate(t_scene *scene)
{
	int	x;
	int	y;
	int	player_count;

	if (scene->map.map_height < 3 || scene->map.map_width < 3)
		return (ERR_SMALL_MAP);
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
					return (ERR_INV_CHAR_MAP);
			}
		}
	}
	if (player_count != 1)
		return (ERR_PLAYER);
	if (check_map_enclosure(scene) != ERR_OK)
		return (ERR_MAP_UNCLOSED);
	return (ERR_OK);
}
