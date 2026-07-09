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
#include "libft.h"

#include <unistd.h>

int		parse_arguments(t_scene *scene, int argc, char *argv[]);

typedef struct s_map_node		//temporary storage for line from map
{
	char				*line;
	struct s_map_node	*next;
}	t_map_node;

int			input_validate(int argc, char **argv);
int			create_map(t_scene *scene, t_map_node *head);
int			check_map_char(t_scene *scene, int x, int y, int *player_count);
int			check_map_enclosure(t_scene *scene);
int			map_validate(t_scene *scene);
void		free_map_list(t_map_node *head);
void		free_visited(char **visited, int count);
void		free_textures(t_scene *scene);
void		free_map_array(char **map_array, int size);
t_map_node	*new_map_node(char *line);
void		add_map_node(t_map_node **head, t_map_node *new_node);
char		*parse_texture_path(char *line, int i);
int			check_type(int type, t_scene *scene, char *line, int *elem_loaded);
int			skip_whitespaces(char *s);
char		*parse_texture_path(char *line, int i);
int			identify_elements(char *line);
int			check_type(int type, t_scene *scene, char *line, int *elem_loaded);
int			parser(t_scene *scene, int argc, char *argv[]);
