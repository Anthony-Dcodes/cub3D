/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:19:02 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 18:24:06 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	assign_line_h(t_vector *vector, int win_h)
{
	vector->line_h = (int)(win_h /  vector->perp_wall_dist);
}
