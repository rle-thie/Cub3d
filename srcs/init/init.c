/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:43:15 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/28 21:16:54 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
	{
		ft_putstr_fd("Error\nCan't malloc data\n", 2);
		exit(EXIT_FAILURE);
	}
	data->garb = malloc(sizeof(t_garbage));
	if (!data->garb)
	{
		ft_putstr_fd("Error\nCan't malloc garbage Collector\n", 2);
		free(data);
		exit(EXIT_FAILURE);
	}
	data->garb->ptr = NULL;
	// data->filename = NULL;
	data->mlx = ft_calloc(sizeof(t_mlx), data);
	data->key = ft_calloc(sizeof(t_key), data);
	return (data);
}

void	init_key(t_data *data)
{
	data->key->key_a = 0;
	data->key->key_d = 0;
	data->key->key_s = 0;
	data->key->key_w = 0;
	data->key->key_la = 0;
	data->key->key_lr = 0;
}

void	init_mlx(t_data *data)
{
	data->mlx->bpp = 0;
	data->mlx->line_length = 0;
	data->mlx->endian = 0;
	data->mlx->addr = NULL;
	data->mlx->ptr = NULL;
	data->mlx->win = NULL;
	data->mlx->img = NULL;
}

void	init_player(t_data *data)
{
	data->player->change = 0;
	data->player->dir = 0;
	data->player->x = 0;
	data->player->y = 0;
	data->player->old_x = 0;
	data->player->old_y = 0;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	data->player->old_dx = 0;
	data->player->old_dy = 0;
}

void	initialise_struct(t_data *data)
{
	init_mlx(data);
	init_key(data);
	init_player(data);
}

t_data	*init(char *filename)
{
	t_data *data;

	data = init_data();
	initialise_struct(data);
	data->height = 900;
	data->width = 1200;
	data->move_speed = 0.06;
	data->rotate_speed = 0.06;
	data->filename = ft_strdup(filename, data);
	printf("%s\n", data->filename);
	return (data);
}