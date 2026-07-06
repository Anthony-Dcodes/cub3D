/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_win_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:21:10 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 18:30:32 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"
#include "render.h"

int	init_mlx_win(t_scene *scene)
{
	int	ret;

	ret = ERR_OK;
	scene->mlx = mlx_init();
	if (scene->mlx == NULL)
		return (ERR_MLX_INIT);
	scene->win = mlx_new_window(scene->mlx, scene->win_w,
			scene->win_h, "cub3D");
	if (scene->win == NULL)
		return (ERR_MLX_WIN);
	scene->frame.img = mlx_new_image(scene->mlx, scene->win_w,
			scene->win_h);
	scene->frame.addr = mlx_get_data_addr(scene->frame.img, &scene->frame.bpp,
			&scene->frame.line_len, &scene->frame.endian);
	ret = load_textures_render(scene);
	if (ret != ERR_OK)
		return (ret);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->frame.img, 0, 0);
	return (ret);
}

void	init_mlx_hooks(t_scene *scene)
{
	mlx_key_hook(scene->win, key_press_hook, scene);
	mlx_hook(scene->win, ON_DESTROY, 0, handle_window_close, scene);
	mlx_loop_hook(scene->mlx, render_scene, scene);
}
