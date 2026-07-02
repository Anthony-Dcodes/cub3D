/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:40:48 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 18:38:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "cub3d.h"
#include "render.h"
#include "parser.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;
	int		ret;

	scene.mlx = mlx_init();
	if (scene.mlx == NULL)
		clean_up(&scene, 1);
	parse_arguments(&scene, argc, argv);
	scene.win = mlx_new_window(scene.mlx, scene.win_w,
			scene.win_h, "cub3D");
	if (scene.win == NULL)
		clean_up(&scene, 1);
	scene.frame.img = mlx_new_image(scene.mlx, scene.win_w,
			scene.win_h);
	scene.frame.addr = mlx_get_data_addr(scene.frame.img, &scene.frame.bpp,
			&scene.frame.line_len, &scene.frame.endian);
	ret = load_textures_render(&scene);
	if (ret != ERR_OK)
		clean_up(&scene, 1);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.frame.img, 0, 0);
	mlx_key_hook(scene.win, key_press_hook, &scene);
	mlx_hook(scene.win, ON_DESTROY, 0, handle_window_close, &scene);
	//mlx_mouse_hook(vars.win, mouse_zoom_hook, &vars);
	mlx_loop_hook(scene.mlx, render_scene, &scene);
	mlx_loop(scene.mlx);
}
