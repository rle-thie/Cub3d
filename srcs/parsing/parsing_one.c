/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:45:46 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/12 22:35:49 by ldevy            ###   ########.fr       */
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
	while (line)
	{
		line = get_next_line(file, data);
		fcking_switch(line, data);
	}
	close(file);
	return (1);
}

int	is_valid_id(char *id)
{
	if (!ft_strncmp(id, "NO", 2))
		return (1);
	if (!ft_strncmp(id, "SO", 2))
		return (2);
	if (!ft_strncmp(id, "WE", 2))
		return (3);
	if (!ft_strncmp(id, "EA", 2))
		return (4);
	if (ft_strlen(id) == 1 && id[0] == 'F')
		return (5);
	if (ft_strlen(id) == 1 && id[0] == 'C')
		return (6);
	return (0);
}

void	fcking_switch(char *line, t_data *data)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (line_split)
	{
		if (is_valid_id(line_split[0]))
			data_fill(data, line_split, is_valid_id(line_split[0]));
		free_split(line_split);
	}
}

void	data_fill(t_data *data, char **line, int index)
{
	char	*txt_path;

	if (!line[1])
	{
		free_split(line);
		err_handling(data, 0, 2);
	}
	txt_path = ft_strdup(line[1], data);
	ft_strtrim(txt_path, "\n", data);
	if (index < 5)
		data->texture[index - 1].path = txt_path;
	else
		convert_to_rgb(data, line, index);
}
