/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:02:27 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 15:41:13 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"
#include <math.h>

static void	perform_vector_calculations(t_vector *vector, t_scene *scene)
{
	assign_ray_dirs(vector, &scene->player);
	assign_delta_dists(vector);
	assign_map_pos(vector, &scene->player);
	assign_step_side_dist(vector, &scene->player);
	dda(vector, scene->map.map);
	assign_perp_wall_dist(vector);
	assign_wall_x(vector, scene);
	assign_line_h(vector, scene->win_h);
	assign_draw_start_end(vector, scene->win_h);
}

int	render_scene(void *param)
{
	t_scene		*scene;
	int			x1;
	int			y1;
	t_vector	vector;

	scene = (t_scene *)param;
	x1 = 0;
	while (x1 < scene->win_w)
	{
		vector.camera_x = (2 * (double)x1 / (double)scene->win_w) - 1;
		perform_vector_calculations(&vector, scene);
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
