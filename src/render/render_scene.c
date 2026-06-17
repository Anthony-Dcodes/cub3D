/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:02:27 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 14:39:44 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"
#include <math.h>

int	render_scene(void *param)
{
	t_scene	*scene;
	int			x1;
	int			y1;
	t_vector	vector;

	scene = (t_scene *)param;
	x1 = 0;
	while (x1 < scene->win_w)
	{
		vector.camera_x = (2 * x1 / scene->win_w) - 1;
		assign_ray_dirs(&vector, &scene->player);
		assign_delta_dists(&vector);
		assign_map_pos(&vector, &scene->player);
		assign_step_side_dist(&vector, &scene->player);
		dda(&vector, scene->map.map);
		assign_perp_wall_dist(&vector);
		assign_line_h(&vector, scene->win_h);
		assign_draw_start_end(&vector, scene->win_h);
		y1 = 0;
		while (y1 < scene->win_h)
		{
			put_scene_pixel(scene, x1, y1, &vector);
			++y1;
		}
		++x1;
	}
	mlx_put_image_to_window(scene->mlx, scene->win, scene->frame.img, 0, 0);
	return (0);
}
