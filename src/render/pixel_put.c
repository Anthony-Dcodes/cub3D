/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:05:10 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 17:29:19 by advorace         ###   ########.fr       */
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
	double	step;
	double	tex_pos;
	int		wall;

	if (y1 < vector->draw_start)
		final_color = scene->ceiling_color;
	else if (y1 > vector->draw_end)
		final_color = scene->floor_color;
	else
	{
		width = scene->texture[NORTH].width;
		heigh = scene->texture[NORTH].height;
		tex_x = (int)(vector->wall_x * width);
		if (tex_x >= width)
			tex_x = width - 1;
		step = (double)heigh / vector->line_h;
		tex_pos = (y1 - scene->win_h / 2.0 + vector->line_h / 2.0) * step;
		tex_y = (int)tex_pos;
		if (tex_y >= heigh)
			tex_y = heigh - 1;
		if (tex_y < 0)
			tex_y = 0;
		wall = get_wall_texture(vector);
		final_color = get_texture_color(&scene->texture[wall], tex_x, tex_y);
		//final_color = MAGENTA;
		//if (vector->side == 1)
		//	final_color = BLUE;
	}
	my_mlx_pixel_put(scene, x1, y1, final_color);
}
