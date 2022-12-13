/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:43:01 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/13 22:24:49 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	err(t_data *data, int mode)
{
	printf("Error\n");
	if (mode == 1)
		printf("cub3d : Bad MAP CHAR extension\n");
	free_all(data);
	exit(EXIT_FAILURE);
}

int	map_check_char(char **map)
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
	return (map_check_char_p2(map));
}

int	map_check_char_p2(char **map)
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
				lettre++;
			j++;
		}
		i++;
	}
	if (lettre != 1)
		return (0);
	return (1);
}

int	last_check(t_data *data)
{
	if (map_check_char(data->map))
		err(data, 1);
	
}
