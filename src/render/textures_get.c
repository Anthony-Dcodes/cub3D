/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:23:04 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 17:26:14 by advorace         ###   ########.fr       */
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