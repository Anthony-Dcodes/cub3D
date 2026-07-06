/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:40:48 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 15:32:53 by advorace         ###   ########.fr       */
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

	ret = ERR_OK;
	ret = parse_arguments(&scene, argc, argv);
	if (ret != ERR_OK)
		clean_up(&scene, ret);
	ret = init_mlx_win(&scene);
	if (ret != ERR_OK)
		clean_up(&scene, ret);
	init_mlx_hooks(&scene);
	mlx_loop(scene.mlx);
	return (ERR_OK);
}
