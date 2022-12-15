/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:43:15 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 16:05:19 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	data->mlx = ft_calloc(sizeof(t_mlx), data);
	data->key = ft_calloc(sizeof(t_key), data);
	data->raytracing = ft_calloc(sizeof(t_raytracing), data);
	data->texture = ft_malloc(sizeof(t_texture) * 4, data);
	data->player = ft_calloc(sizeof(t_player), data);
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

t_data	*init(char *filename)
{
	t_data	*data;

	data = init_data();
	init_mlx(data);
	init_key(data);
	initialise_struct(data);
	data->height = 900;
	data->width = 1200;
	data->move_speed = 0.06;
	data->rotate_speed = 0.06;
	data->c_color = -1;
	data->f_color = -1;
	data->filename = ft_strdup(filename, data);
	data->head_map = NULL;
	return (data);
}
