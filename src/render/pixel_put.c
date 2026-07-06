/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:05:10 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 17:02:24 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	dst = scene->frame.addr + (y * scene->frame.line_len + x
			* (scene->frame.bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_scene_pixel(t_scene *scene, int x1, int y1, t_vector *vector)
{
	int	final_color;
	int	tex_x;
	int	tex_y;
	int	wall;

	if (y1 < vector->draw_start)
		final_color = scene->ceiling_color;
	else if (y1 > vector->draw_end)
		final_color = scene->floor_color;
	else
	{
		wall = get_wall_texture(vector);
		tex_x = get_texture_xpos(scene, vector, wall);
		tex_y = get_texture_ypos(scene, vector, y1, wall);
		final_color = get_texture_color(&scene->texture[wall], tex_x, tex_y);
	}
	my_mlx_pixel_put(scene, x1, y1, final_color);
}
