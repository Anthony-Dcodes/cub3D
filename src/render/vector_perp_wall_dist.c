/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_perp_wall_dist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:18:12 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 15:37:31 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	assign_perp_wall_dist(t_vector *vector)
{
	if (vector->side == 0)
	{
		vector->perp_wall_dist = (vector->side_dist_x - vector->delta_dist_x);
	}
	else
	{
		vector->perp_wall_dist = (vector->side_dist_y - vector->delta_dist_y);
	}
}
