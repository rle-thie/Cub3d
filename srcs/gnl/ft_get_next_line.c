/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:24:54 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/09 16:44:23 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*free_ptr(char *tab, t_data *data)
{
	ft_free(tab, data);
	return (NULL);
}

static char	*ft_strtrim_front(char *str, t_data *data)
{
	char		*stat;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (free_ptr(str, data));
	stat = ft_malloc(sizeof(char) * (ft_strlen(str) - i + 1), data);
	if (!stat)
		return (NULL);
	stat[(ft_strlen(str) - i) - 1] = '\0';
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		stat[y] = str[i];
		i++;
		y++;
	}
	ft_free(str, data);
	return (stat);
}

static char	*read_buff(int fd, char *stat, int buffer_size, t_data *data)
{
	int		count;
	char	*buf;

	count = 1;
	buf = ft_malloc(sizeof(char) * buffer_size + 1, data);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (ft_strchr(buf, '\n') == 0 && count > 0)
	{
		count = read(fd, buf, buffer_size);
		if (count < 0)
			break ;
		buf[count] = '\0';
		stat = ft_strjoin_gc(stat, buf, data);
	}
	ft_free(buf, data);
	return (stat);
}

static char	*read_line(char *str, t_data *data)
{
	char	*line;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = ft_malloc(sizeof(char) * i + 1, data);
	else
		line = ft_malloc(sizeof(char) * i + 2, data);
	if (!line)
		return (free_ptr(line, data));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd, t_data *data)
{
	static char	*buf;
	char		*line;
	int			buffer_size;

	buffer_size = 1;
	if (fd < 0 || buffer_size < 1)
		return (NULL);
	if (!buf)
	{
		buf = ft_malloc(sizeof(char) * 1, data);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	buf = read_buff(fd, buf, buffer_size, data);
	if (!buf)
		return (NULL);
	line = read_line(buf, data);
	buf = ft_strtrim_front(buf, data);
	return (line);
}
