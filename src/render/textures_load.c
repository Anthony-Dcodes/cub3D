/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:14:06 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 18:37:38 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"

// Need to add error handling and cleanup later
int	load_textures_render(t_scene *scene)
{
	int	ret;

	ret = load_texture_render(scene, &scene->texture[NORTH], scene->tex_paths[NORTH]);
	if (ret != ERR_OK)
		return (ret);
	ret = load_texture_render(scene, &scene->texture[SOUTH], scene->tex_paths[SOUTH]);
	if (ret != ERR_OK)
		return (ret);
	ret = load_texture_render(scene, &scene->texture[EAST], scene->tex_paths[EAST]);
	if (ret != ERR_OK)
		return (ret);
	ret = load_texture_render(scene, &scene->texture[WEST], scene->tex_paths[WEST]);
	if (ret != ERR_OK)
		return (ret);
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
