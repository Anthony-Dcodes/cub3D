/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:05:10 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 15:14:56 by advorace         ###   ########.fr       */
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
	int	width;
	int	heigh;

	if (y1 < vector->draw_start)
		final_color = scene->ceiling_color;
	else if (y1 > vector->draw_end)
		final_color = scene->floor_color;
	else
	{
		width = scene->texture[NORTH].width;
		heigh = scene->texture[NORTH].height;
		tex_x = (int)(vector->map_x * width);
		if (tex_x >= width)
			tex_x = width - 1;
		tex_y = 
		final_color = get_texture_color(&scene->texture[NORTH], x1, y1);
		//final_color = MAGENTA;
		//if (vector->side == 1)
		//	final_color = BLUE;
	}
	my_mlx_pixel_put(scene, x1, y1, final_color);
}
