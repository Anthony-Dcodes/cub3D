/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:54:31 by advorace          #+#    #+#             */
/*   Updated: 2026/07/12 16:58:11 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "render.h"

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
	get_new_player_pos(scene, keycode);
	rotate_player(&scene->player, keycode);
	return (0);
}
