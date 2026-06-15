/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:02:27 by advorace          #+#    #+#             */
/*   Updated: 2026/06/15 14:24:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"

int	render_scene(void *param)
{
	t_player	*player;
	int			x1;
	int			y1;

	player = (t_player *)param;
	y1 = 0;
	while (y1 < player->mlx_struct.win_height)
	{
		x1 = 0;
		while (x1 < player->mlx_struct.win_width)
		{
			put_scene_pixel(player, x1, y1);
			++x1;
		}
		++y1;
	}
	mlx_put_image_to_window(player->mlx_struct.mlx, player->mlx_struct.win,
		player->mlx_struct.img, 0, 0);
	return (0);
}
