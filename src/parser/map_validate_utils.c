/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:00:10 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/07 20:00:10 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static void	set_vec(double *x, double *y, double val_x, double val_y)
{
	*x = val_x;
	*y = val_y;
}

static void	set_player_dir(t_player *player, char c)
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
		return (ERR_INV_CHAR_MAP);
	if (ft_strchr("NSEW", c))
	{
		(*player_count)++;
		scene->player.pos_x = x + 0.5;
		scene->player.pos_y = y + 0.5;
		set_player_dir(&scene->player, c);
	}
	return (ERR_OK);
}
