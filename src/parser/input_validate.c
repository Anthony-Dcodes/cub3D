/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:09:53 by msnizek           #+#    #+#             */
/*   Updated: 2026/06/21 22:09:53 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	input_validate(int argc, char **argv)
{
	int		fd;
	int		len;
	char	*path;

	if (argc != 2)
		return (ERR_ARGS);
	path = argv[1];
	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (ERR_ARGS);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERR_ARGS);
	close(fd);
	return (ERR_OK);
}
