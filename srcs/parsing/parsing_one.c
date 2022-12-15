/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:45:46 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/15 13:43:52 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	extension_check(char *str, t_data *data)
{
	char	*ext;
	int		size;

	size = ft_strlen(str);
	if (size <= 4)
		err_handling(data, 0, 1);
	ext = &(str[size - 4]);
	if (ft_strncmp(ext, ".cub", 5))
		err_handling(data, 0, 1);
}

int	parsing(t_data *data)
{
	char	*line;
	int		file;

	extension_check(data->filename, data);
	file = open(data->filename, O_RDONLY);
	if (file == -1)
		err_handling(data, file, 0);
	line = "";
	data->map = NULL;
	while (line)
	{
		line = get_next_line(file, data);
		if (!is_data_full(data))
			data_mode(line, data, file);
		else
		{
			map_mode(line, data, file);
			break ;
		}
	}
	close(file);
	last_check(data);
	return (1);
}

int	is_valid_id(char *id)
{
	if (!ft_strncmp(id, "NO", 3))
		return (1);
	if (!ft_strncmp(id, "SO", 3))
		return (2);
	if (!ft_strncmp(id, "WE", 3))
		return (3);
	if (!ft_strncmp(id, "EA", 3))
		return (4);
	if (ft_strlen(id) == 1 && id[0] == 'F')
		return (5);
	if (ft_strlen(id) == 1 && id[0] == 'C')
		return (6);
	return (0);
}

void	data_mode(char *line, t_data *data, int file)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (line_split)
	{
		if (is_valid_id(line_split[0]))
			data_fill(data, line_split, is_valid_id(line_split[0]), file);
		free_split(line_split);
	}
}

void	data_fill(t_data *data, char **line, int index, int file)
{
	char	*txt_path;

	if (line[1] && line[1][0] == '\n')
	{
		free_split(line);
		close(file);
		err_handling(data, 0, 2);
	}
	txt_path = ft_strdup(line[1], data);
	txt_path = ft_strtrim(txt_path, "\n", data);
	ext_xpm_check(txt_path, data, file);
	if (index < 5)
		data->texture[index - 1].path = txt_path;
	else
		convert_to_rgb(data, line, index, file);
}
