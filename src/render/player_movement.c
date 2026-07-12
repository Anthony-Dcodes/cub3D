/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:49:15 by advorace          #+#    #+#             */
/*   Updated: 2026/07/12 16:58:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "render.h"

static void	init_new_pos(double *new_posx, double *new_posy)
{
	*new_posx = 0;
	*new_posy = 0;
	return ;
}

void	get_new_player_pos(t_scene *scene, int keycode)
{
	double	new_posx;
	double	new_posy;

	init_new_pos(&new_posx, &new_posy);
	if (keycode == KEY_W)
	{
		new_posx = MOVE_SPEED * scene->player.dir_x;
		new_posy = MOVE_SPEED * scene->player.dir_y;
	}
	else if (keycode == KEY_S)
	{
		new_posx = MOVE_SPEED * scene->player.dir_x;
		new_posy = MOVE_SPEED * scene->player.dir_y;
	}
	else if (keycode == KEY_A)
	{
		new_posx = MOVE_SPEED * scene->player.dir_y;
		new_posy = MOVE_SPEED * -scene->player.dir_x;
	}
	else if (keycode == KEY_D)
	{
		new_posx = MOVE_SPEED * -scene->player.dir_y;
		new_posy = MOVE_SPEED * scene->player.dir_x;
	}
	update_player_pos(scene, new_posx, new_posy, keycode);
}

void	update_player_pos(t_scene *scene, double new_posx,
		double new_posy, int keycode)
{
	int	val_posx;
	int	val_posy;

	val_posx = (int)(new_posx + scene->player.pos_x);
	val_posy = (int)(new_posy + scene->player.pos_y);
	if (scene->map.map[val_posy][val_posx] == '1')
		return ;
	if (keycode == KEY_S)
	{
		scene->player.pos_x -= new_posx;
		scene->player.pos_y -= new_posy;
		return ;
	}
	scene->player.pos_x += new_posx;
	scene->player.pos_y += new_posy;
	return ;
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
