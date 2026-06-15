/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:40:48 by advorace          #+#    #+#             */
/*   Updated: 2026/06/15 14:12:32 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "cub3d.h"
#include "render.h"
#include "parser.h"

int	main(int argc, char *argv[])
{
	t_player	player;

	if (argc != 2)
		return (1);
	player.mlx_struct.mlx = mlx_init();
	if (player.mlx_struct.mlx == NULL)
		clean_up(&player, -1);
	parse_arguments(&player, argc, argv);
	player.mlx_struct.win = mlx_new_window(player.mlx_struct.mlx, player.mlx_struct.win_width,
			player.mlx_struct.win_height, "cub3D");
	if (player.mlx_struct.win == NULL)
		clean_up(&player, -1);
	player.mlx_struct.img = mlx_new_image(player.mlx_struct.mlx, player.mlx_struct.win_width,
			player.mlx_struct.win_height);
	player.mlx_struct.i_addr = mlx_get_data_addr(player.mlx_struct.img, &player.mlx_struct.i_bits_per_pixel,
			&player.mlx_struct.i_line_length, &player.mlx_struct.i_endian);
	mlx_put_image_to_window(player.mlx_struct.mlx, player.mlx_struct.win, player.mlx_struct.img, 0, 0);
	//mlx_key_hook(vars.win, key_press_hook, &vars);
	//mlx_hook(vars.win, ON_DESTROY, 0, handle_window_close, &vars);
	//mlx_mouse_hook(vars.win, mouse_zoom_hook, &vars);
	mlx_loop_hook(player.mlx_struct.mlx, render_scene, &player);
	mlx_loop(player.mlx_struct.mlx);
}
