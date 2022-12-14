/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:43:01 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/14 16:47:24 by ldevy            ###   ########.fr       */
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
		return (1);
	return (0);
}

int	last_check(t_data *data)
{
	if (!is_data_full(data))
		err(data, 3);
	if (map_check_char(data->map))
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
				printf("i : %d j : %d char : %c\n", i, j, map[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_coords_check(int i, int j, char **map, char c)
{
	if (!(c == '1' || c == ' ') && i == 0)
		return (1);
	else if ((c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		&& map_nb_ck(map, i, j))
		return (1);
	return (0);
}

int	map_nb_ck(char **map, int i, int j)
{
	if (i == 0 || j == 0 || !can_check(map, i, j))
		return (1);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
	|| map[i][j - 1] == ' ' || map[i][j + 1] == ' '
	|| map[i + 1][j + 1] == ' ' || map[i + 1][j - 1] == ' '
	|| map[i - 1][j - 1] == ' ' || map[i - 1][j + 1] == ' ')
		return (1);
	if (map[i - 1][j] == '\n' || map[i + 1][j] == '\n'
	|| map[i][j - 1] == '\n' || map[i][j + 1] == '\n'
	|| map[i + 1][j + 1] == '\n' || map[i + 1][j - 1] == '\n'
	|| map[i - 1][j - 1] == '\n' || map[i - 1][j + 1] == '\n')
		return (1);
	return (0);
}

int	can_check(char **map, int i, size_t j)
{
	if (j > ft_strlen(map[i - 1]))
		return (0);
	if (!map[i + 1] || j > ft_strlen(map[i + 1]))
		return (0);
	return (1);
}