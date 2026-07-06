/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:14:06 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 17:33:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"

// Need to add error handling and cleanup later
int	load_textures_render(t_scene *scene)
{
	int	ret;
	int	i;

	ret = ERR_OK;
	i = 0;
	while (i < 4)
	{
		ret = load_texture_render(scene, &scene->texture[i], scene->tex_paths[i]);
		if (ret != ERR_OK)
			return (ret);
		++i;
	}
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
