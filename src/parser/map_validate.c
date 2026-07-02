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
		scene->player.pos_x = x + 0,5;
		scene->player.pos_y = y + 0,5;
		set_player_dir(&scene->player, c);
	}
	return (ERR_OK);
}

int	flood_fill(t_scene *scene, char **visited, int y, int x)
{
	if (y >= scene->map.map_height || x >= (int)ft_strlen(visited[y]) || y < 0 || x < 0)
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

int	is_empty_line(char *line)
{
	int	i;

	i = skip_whitespaces(line);
	if (line == '\n' || line == '\0')
		return (1);
	return (0);
}
