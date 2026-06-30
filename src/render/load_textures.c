/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:14:06 by advorace          #+#    #+#             */
/*   Updated: 2026/06/30 14:44:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"

// Need to add error handling and cleanup later
int	load_textures_render(t_scene *scene)
{
	load_texture_render(scene, &scene->texture[NORTH], scene->tex_paths[NORTH]);
	load_texture_render(scene, &scene->texture[SOUTH], scene->tex_paths[SOUTH]);
	load_texture_render(scene, &scene->texture[EAST], scene->tex_paths[EAST]);
	load_texture_render(scene, &scene->texture[WEST], scene->tex_paths[WEST]);
	return (ERR_OK);
}

int	load_texture_render(t_scene *scene, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(scene->mlx, path,
		&tex->width, &tex->height);
	if (!tex->img)
	{
		return (ERR_TEXTURES);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
		&tex->line_len, &tex->endian);
	return (ERR_OK);
}
