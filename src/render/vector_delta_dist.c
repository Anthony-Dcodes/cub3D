/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delta_dist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:16:52 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 18:19:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "math.h"

void assign_delta_dists(t_vector *vector)
{
	// For DDA only ratios not the absolute values are needed
	vector->delta_dist_x = fabs(1 / vector->ray_dir_x);
	vector->delta_dist_y = fabs(1 / vector->ray_dir_y);
}