/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:49:15 by advorace          #+#    #+#             */
/*   Updated: 2026/07/09 16:32:32 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "render.h"

void	move_player(t_player *player, int keycode)
{
	if (keycode == KEY_W)
	{
		player->pos_x += MOVE_SPEED * player->dir_x;
		player->pos_y += MOVE_SPEED * player->dir_y;
	}
	else if (keycode == KEY_S)
	{
		player->pos_x -= MOVE_SPEED * player->dir_x;
		player->pos_y -= MOVE_SPEED * player->dir_y;
	}
	else if (keycode == KEY_A)
	{
		player->pos_x += MOVE_SPEED * player->dir_y;
		player->pos_y += MOVE_SPEED * -player->dir_x;
	}
	else if (keycode == KEY_D)
	{
		player->pos_x += MOVE_SPEED * -player->dir_y;
		player->pos_y += MOVE_SPEED * player->dir_x;
	}
}

void	rotate_player(t_player *player, int keycode)
{
	if (keycode == KEY_LEFT)
		rotate(player, -ROT_SPEED);
	else if (keycode == KEY_RIGHT)
		rotate(player, ROT_SPEED);
}

void	rotate(t_player *player, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotate_speed)
		- player->dir_y * sin(rotate_speed);
	player->dir_y = old_dir_x * sin(rotate_speed)
		+ player->dir_y * cos(rotate_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotate_speed)
		- player->plane_y * sin(rotate_speed);
	player->plane_y = old_plane_x * sin(rotate_speed)
		+ player->plane_y * cos(rotate_speed);
}
