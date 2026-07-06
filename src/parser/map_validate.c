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

void	set_vec(double *x, double *y, double val_x, double val_y)
{
	*x = val_x;
	*y = val_y;
}

void	set_player_dir(t_player *player, char c)
{
	if (c == 'N')
	{
		set_vec(&player->dir_x, &player->dir_y, 0, -1);
		set_vec(&player->plane_x, &player->plane_y, 0.66, 0);
	}
	else if (c == 'S')
	{
		set_vec(&player->dir_x, &player->dir_y, 0, 1);
		set_vec(&player->plane_x, &player->plane_y, -0.66, 0);
	}
	else if (c == 'E')
	{
		set_vec(&player->dir_x, &player->dir_y, 1, 0);
		set_vec(&player->plane_x, &player->plane_y, 0, 0.66);
	}
	else if (c == 'W')
	{
		set_vec(&player->dir_x, &player->dir_y, -1, 0);
		set_vec(&player->plane_x, &player->plane_y, 0, -0.66);
	}
}

int	check_map_char(t_scene *scene, int x, int y, int *player_count)
{
	char	c;

	c = scene->map.map[y][x];
	if (!ft_strchr("01NSEW ", c))
		return (printf("Error\nWrong character in map"), ERR_MAP);
	if (ft_strchr("NSEW", c))
	{
		(*player_count)++;
		scene->player.pos_x = x + 0.5;
		scene->player.pos_y = y + 0.5;
		set_player_dir(&scene->player, c);
	}
	return (ERR_OK);
}

int	flood_fill(t_scene *scene, char **visited, int y, int x)
{
	if (y < 0 || y >= scene->map.map_height || x < 0 || x >= (int)ft_strlen(visited[y]))
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

void	free_visited(char **visited, int count)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < count)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	check_map_enclosure(t_scene *scene)
{
	char	**visited;
	int		i;
	int		result;

	visited = malloc(sizeof(char *) * scene->map.map_height);
	if (!visited)
		return (ERR_MALLOC);
	i = 0;
	while (i < scene->map.map_height)
	{
		visited[i] = ft_strdup(scene->map.map[i]);
		if (!visited[i])
			return (free_visited(visited, i), ERR_MALLOC);
		i++;
	}
	result = flood_fill(scene, visited, (int)scene->player.pos_y, (int)scene->player.pos_x);
	free_visited(visited, scene->map.map_height);
	if (result != 0)
		return (printf("Error:\nMap is not enclosed by walls\n"), ERR_MAP);
	return (ERR_OK);
}

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
		return (printf("Error:\nToo many players"), ERR_MAP);
	if (check_map_enclosure(scene) != ERR_OK)
		return (ERR_MAP);
	return (ERR_OK);
}
