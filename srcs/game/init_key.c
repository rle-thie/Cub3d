/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:43:29 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:48:51 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_event(int key_pressed, t_data *data)
{
	if (key_pressed == 119)
		data->key->key_w = 1;
	if (key_pressed == 115)
		data->key->key_s = 1;
	if (key_pressed == 97)
		data->key->key_a = 1;
	if (key_pressed == 100)
		data->key->key_d = 1;
	if (key_pressed == 65363)
		data->key->key_lr = 1;
	if (key_pressed == 65361)
		data->key->key_la = 1;
	if (key_pressed == 65307)
		ft_exit_esc(data);
	return (0);
}

int	restore_key(int key_pressed, t_data *data)
{
	if (key_pressed == 119)
		data->key->key_w = 0;
	if (key_pressed == 115)
		data->key->key_s = 0;
	if (key_pressed == 97)
		data->key->key_a = 0;
	if (key_pressed == 100)
		data->key->key_d = 0;
	if (key_pressed == 65363)
		data->key->key_lr = 0;
	if (key_pressed == 65361)
		data->key->key_la = 0;
	return (0);
}

void	update_position(t_data *data)
{
	if (data->key->key_w == 1)
		move_forward(data);
	if (data->key->key_s == 1)
		move_backward(data);
	if (data->key->key_a == 1)
		move_left(data);
	if (data->key->key_d == 1)
		move_right(data);
	if (data->key->key_la == 1)
		rotate_left(data);
	if (data->key->key_lr == 1)
		rotate_right(data);
}

void	mlx_init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx->ptr,
				data->texture[i].path, &data->texture[i].w,
				&data->texture[i].h);
		if (!data->texture[i].img)
			ft_free_exit("XPM image reading has failed", 1, data);
		data->texture[i].addr = (int *)mlx_get_data_addr(data->texture[i].img,
				&data->texture[i].bpp, &data->texture[i].line_length,
				&data->texture[i].endian);
		if (!data->texture[i].addr)
			ft_free_exit("XPM address reading has failed", 1, data);
		i++;
	}
}

void	init_game(t_data *data)
{
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		ft_free_exit("Can't init mlx ptr", 1, data);
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->width,
			data->height, "Cub3d");
	if (!data->mlx->win)
		ft_free_exit("Can't init mlx window", 1, data);
	data->mlx->img = mlx_new_image(data->mlx->ptr, data->width, data->height);
	if (!data->mlx->img)
		ft_free_exit("Can't init mlx image", 1, data);
	data->mlx->addr = (int *)mlx_get_data_addr(data->mlx->img, &data->mlx->bpp, \
		&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->addr)
		ft_free_exit("Can't init mlx addr", 1, data);
	mlx_init_textures(data);
}
