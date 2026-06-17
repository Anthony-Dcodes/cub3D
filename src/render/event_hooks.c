/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:54:31 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 16:44:12 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

// static void	move_screen(t_vars *vars, int keycode)
// {
// 	long double	step_x;
// 	long double	step_y;

// 	step_x = (vars->x_max - vars->x_min) * 0.05;
// 	step_y = (vars->y_max - vars->y_min) * 0.05;
// 	if (keycode == KEY_LEFT)
// 	{
// 		vars->x_min -= step_x;
// 		vars->x_max -= step_x;
// 	}
// 	else if (keycode == KEY_RIGHT)
// 	{
// 		vars->x_min += step_x;
// 		vars->x_max += step_x;
// 	}
// 	else if (keycode == KEY_UP)
// 	{
// 		vars->y_min += step_y;
// 		vars->y_max += step_y;
// 	}
// 	else if (keycode == KEY_DOWN)
// 	{
// 		vars->y_min -= step_y;
// 		vars->y_max -= step_y;
// 	}
// }

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
		player->pos_x += MOVE_SPEED * -player->dir_y;
		player->pos_y += MOVE_SPEED * player->dir_x;
	}
	else if (keycode == KEY_D)
	{
		player->pos_x += MOVE_SPEED * player->dir_y;
		player->pos_y += MOVE_SPEED * -player->dir_x;
	}
}

int	handle_window_close(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	clean_up(scene, ERR_OK);
	return (0);
}

int	key_press_hook(int keycode, void	*param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keycode == KEY_ESC)
		clean_up(scene, ERR_OK);
	move_player(&scene->player, keycode);
	return (0);
}