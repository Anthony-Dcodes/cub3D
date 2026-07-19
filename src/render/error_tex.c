/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:25:48 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/19 17:05:33 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "cub3d.h"
#include "render.h"
#include "libft.h"

void	error_parser_tex(int err)
{
	if (err == ERR_DUP_TEX_FLAG)
		ft_putstr_fd("Textures have same flag", 2);
	else if (err == ERR_DUP_TEX_PATH || err == ERR_INV_PATH_TEX
		|| err == ERR_MISSING_PATH_TEX)
		ft_putstr_fd("Textures have same, invalid or missing path", 2);
	else if (err == ERR_INV_CHAR_TEX)
		ft_putstr_fd("After texture is unspecified data", 2);
	else if (err == ERR_MISSING_TEX)
		ft_putstr_fd("Texture is missing", 2);
}
