/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:10:41 by advorace          #+#    #+#             */
/*   Updated: 2026/06/25 19:06:42 by msnizek          ###   ########.fr       */
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

int		input_validate(int argc, char **argv);
int		skip_whitespaces(char *s);
char	*parse_texture_path(char *line, int i);
int		get_single_rgb(char *line, int *i);
int		identify_elements(char *line);
int		parse_color(char *line, int i, int *color_dest);
int		load_texture(int type, t_scene *scene, char *line, int *elem_loaded);
int		load_color(int type, t_scene *scene, char *line, int *elem_loaded);
int		check_type(int type, t_scene *scene, char *line, int *elem_loaded);
