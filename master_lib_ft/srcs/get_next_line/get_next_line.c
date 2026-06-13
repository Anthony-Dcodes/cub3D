/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:27 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 20:54:59 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

static char	*new_line_stash(char *stash, int stash_line)
{
	char	*ptr;
	char	*new;
	size_t	len;

	ptr = ft_strchr(stash, '\n');
	if (stash_line == 1)
	{
		if (ptr)
			len = ptr - stash + 1;
		else
			len = ft_strlen(stash);
		ptr = stash;
	}
	if (stash_line == 0)
	{
		if (!ptr || !*(++ptr))
			return (NULL);
		len = ft_strlen(ptr);
	}
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, len);
	new[len] = '\0';
	return (new);
}

static int	cleanup_init(char **buf, char **st, ssize_t b_read, int init_st)
{
	if (b_read == -1)
	{
		free(*buf);
		*buf = NULL;
		if (*st)
		{
			free(*st);
			*st = NULL;
		}
		return (0);
	}
	if (!*st && init_st)
	{
		*st = malloc(1);
		if (!*st)
		{
			free(*buf);
			*buf = NULL;
			return (0);
		}
		(*st)[0] = '\0';
	}
	return (1);
}

static char	*return_line_update_stash(char **stash, char **buf)
{
	char	*n_line;
	char	*tmp;

	if (!stash || !*stash || !buf)
	{
		free(*buf);
		*buf = NULL;
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	n_line = new_line_stash(*stash, 1);
	tmp = new_line_stash(*stash, 0);
	free(*stash);
	*stash = tmp;
	free(*buf);
	*buf = NULL;
	if (!n_line || !stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (n_line);
}

static char	*read_and_process(int fd, char **stash, char **buf)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, *buf, BUFFER_SIZE);
	if (!cleanup_init(buf, stash, bytes_read, 0))
		return (NULL);
	while (bytes_read > 0)
	{
		(*buf)[bytes_read] = '\0';
		if (!cleanup_init(buf, stash, bytes_read, 1))
			return (NULL);
		*stash = join_and_free(stash, buf);
		if (!*stash)
			return (NULL);
		if (ft_strchr(*stash, '\n'))
			return (return_line_update_stash(stash, buf));
		bytes_read = (read(fd, *buf, BUFFER_SIZE));
		if (!cleanup_init(buf, stash, bytes_read, 0))
			return (NULL);
	}
	if (*stash)
		return (return_line_update_stash(stash, buf));
	free(*buf);
	*buf = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		if (!cleanup_init(&buf, &stash, -1, 0))
			return (NULL);
	}
	return (read_and_process(fd, &stash, &buf));
}
