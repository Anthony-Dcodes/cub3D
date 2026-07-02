/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:10:41 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 15:22:06 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"

void	parse_arguments(t_scene *scene, int argc, char *argv[]);

typedef struct s_map_node		//temporary storage for line from map
{
	char				*line;
	struct s_map_node	*next;
}	t_map_node;

