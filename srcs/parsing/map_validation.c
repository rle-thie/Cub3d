/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:43:01 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/15 15:08:57 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	err(t_data *data, int mode)
{
	printf("Error\n");
	if (mode == 1)
		printf("cub3d : Bad MAP CHAR\n");
	if (mode == 2)
		printf("cub3d : Bad MAP INVALID\n");
	if (mode == 3)
		printf("cub3d : Missing DATA \n");
	free_all(data);
	exit(EXIT_FAILURE);
}

int	map_check_char(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' ' ||
			map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
			|| map[i][j] == 'W'))
				return (0);
			j++;
		}
		i++;
	}
	return (map_check_char_p2(map, data));
}

int	map_check_char_p2(char **map, t_data *data)
{
	int	i;
	int	j;
	int	lettre;

	lettre = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
			|| map[i][j] == 'W')
			{
				add_player(data, i, j, map[i][j]);
				lettre++;
			}
			j++;
		}
		i++;
	}
	if (lettre != 1)
		return (1);
	return (0);
}

int	last_check(t_data *data)
{
	if (!is_data_full(data))
		err(data, 3);
	if (map_check_char(data->map, data))
		err(data, 1);
	if (map_validation(data->map))
		err(data, 2);
	return (1);
}

int	map_validation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map_coords_check(i, j, map, map[i][j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
