/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:23:04 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 17:01:52 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

int	get_texture_color(t_img *tex, int x, int y)
{
	char	*pixel;

	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *) pixel);
}

int	get_wall_texture(t_vector *vector)
{
	if (vector->side == 0)
	{
		if (vector->ray_dir_x > 0)
			return (WEST);
		return (EAST);
	}
	if (vector->ray_dir_y > 0)
		return (NORTH);
	return (SOUTH);
}

int	get_texture_xpos(t_scene *scene, t_vector *vector, int wall)
{
	int	width;
	int	tex_x;

	width = scene->texture[wall].width;
	tex_x = (int)(vector->wall_x * width);
	if (tex_x >= width)
		tex_x = width - 1;
	return (tex_x);
}

int	get_texture_ypos(t_scene *scene, t_vector *vector, int y1, int wall)
{
	int		height;
	int		tex_y;
	double	step;
	double	tex_pos;

	height = scene->texture[wall].height;
	step = (double)height / vector->line_h;
	tex_pos = (y1 - scene->win_h / 2.0 + vector->line_h / 2.0) * step;
	tex_y = (int)tex_pos;
	if (tex_y >= height)
		tex_y = height - 1;
	if (tex_y < 0)
		tex_y = 0;
	return (tex_y);
}
