/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:10:41 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 15:33:18 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"

int		parse_arguments(t_scene *scene, int argc, char *argv[]);

int		input_validate(int argc, char **argv);
int		skip_whitespaces(char *s);
char	*parse_texture_path(char *line, int i);
int		get_single_rgb(char *line, int *i);
int		identify_elements(char *line);
int		parse_color(char *line, int i, int *color_dest);
int		load_texture(int type, t_scene *scene, char *line, int *elem_loaded);
int		load_color(int type, t_scene *scene, char *line, int *elem_loaded);
int		check_type(int type, t_scene *scene, char *line, int *elem_loaded);
