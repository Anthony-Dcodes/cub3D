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

static int	flood_fill(t_scene *scene, char **visited, int y, int x)
{
	if (y < 0 || y >= scene->map.map_height || x < 0
		|| x >= (int)ft_strlen(visited[y]))
		return (1);
	if (visited[y][x] == ' ')
		return (1);
	if (scene->map.map[y][x] == '1' || visited[y][x] == 'V')
		return (0);
	visited[y][x] = 'V';
	return (flood_fill(scene, visited, y - 1, x)
		|| flood_fill(scene, visited, y + 1, x)
		|| flood_fill(scene, visited, y, x - 1)
		|| flood_fill(scene, visited, y, x + 1));
}

static char	**init_visited_map(t_scene *scene)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(char *) * scene->map.map_height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < scene->map.map_height)
	{
		visited[i] = ft_strdup(scene->map.map[i]);
		if (!visited[i])
			return (free_visited(visited, i), NULL);
		i++;
	}
	return (visited);
}

int	check_map_enclosure(t_scene *scene)
{
	char	**visited;
	int		i;
	int		j;

	visited = init_visited_map(scene);
	if (!visited)
		return (ERR_MALLOC);
	i = -1;
	while (++i < scene->map.map_height)
	{
		j = -1;
		while (++j < scene->map.map_width)
		{
			if (ft_strchr("0NSEW", visited[i][j]))
			{
				if (flood_fill(scene, visited, i, j) != 0)
				{
					free_visited(visited, scene->map.map_height);
					return (ERR_MAP_UNCLOSED);
				}
			}
		}
	}
	free_visited(visited, scene->map.map_height);
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
