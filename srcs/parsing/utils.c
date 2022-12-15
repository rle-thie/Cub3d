/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:20:17 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/15 13:43:28 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	err_handling(t_data *data, int file, int mode)
{
	printf("Error\n");
	if (mode)
	{
		if (mode == 1)
			printf("cub3d : Bad file extension\n");
		if (mode == 2)
			printf("cub3d : Bad format in file\n");
		if (mode == 3)
		{
			printf("cub3d : Bad MAP format in file\n");
			close(file);
		}
		free_all(data);
		exit(EXIT_FAILURE);
	}
	perror("cub3d ");
	close(file);
	free_all(data);
	exit(EXIT_FAILURE);
}

void	free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	if (ptr)
		free(ptr);
}

void	convert_to_rgb(t_data *data, char **line, int index, int file)
{
	char	**nbrs;
	int		val;

	if (!line[1])
	{
		free_split(line);
		close(file);
		err_handling(data, 0, 2);
	}
	nbrs = ft_split(line[1], ',');
	if (nbrs)
		val = check_args(nbrs, data);
	else
	{
		close(file);
		err_handling(data, 0, 2);
	}
	if (index == 5)
		data->f_color = val;
	if (index == 6)
		data->c_color = val;
}

int	check_args(char **tab, t_data *data)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0
			|| tab[i][0] == '\n' || tab[i][0] == ' ')
			break ;
		i++;
	}
	if (i != 3)
	{
		free_split(tab);
		err_handling(data, 0, 2);
	}
	i = convert_trgb(0, ft_atoi(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
	free_split(tab);
	return (i);
}

int	is_data_full(t_data *data)
{
	int	i;

	i = 0;
	if (data->c_color != -1)
		i++;
	if (data->f_color != -1)
		i++;
	if (data->texture[0].path)
		i++;
	if (data->texture[1].path)
		i++;
	if (data->texture[2].path)
		i++;
	if (data->texture[3].path)
		i++;
	if (i == 6)
		return (1);
	return (0);
}
