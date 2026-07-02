/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_draw_start_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:23:45 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 18:23:59 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	assign_draw_start_end(t_vector *vector, int win_h)
{
	vector->draw_start = (int)((win_h - vector->line_h) / 2);
	if (vector->draw_start < 0)
		vector->draw_start = 0;
	vector->draw_end = (int)((win_h + vector->line_h) / 2);
	if (vector->draw_end >= win_h)
		vector->draw_end = win_h - 1;
}