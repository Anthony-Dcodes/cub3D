/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:02:27 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 10:27:58 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"

int	render_scene(void *param)
{
	t_scene	*scene;
	int			x1;
	int			y1;

	scene = (t_scene *)param;
	y1 = 0;
	while (y1 < scene->win_h)
	{
		x1 = 0;
		while (x1 < scene->win_w)
		{
			put_scene_pixel(scene, x1, y1);
			++x1;
		}
		++y1;
	}
	mlx_put_image_to_window(scene->mlx, scene->win, scene->frame.img, 0, 0);
	return (0);
}
