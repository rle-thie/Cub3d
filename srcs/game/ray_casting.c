/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:58:41 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/12 20:11:29 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mlx_init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx->ptr, data->texture[i].path, &data->texture[i].w, &data->texture[i].h);
		if (!data->texture[i].img)
			ft_free_exit("XPM image reading has failed", 1, data);
		data->texture[i].addr = (int *)mlx_get_data_addr(data->texture[i].img, &data->texture[i].bpp, &data->texture[i].line_length, &data->texture[i].endian);
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
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->width, data->height, "Cub3d");
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



void	render_ray(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		ray_dir(data, x);
		render_steps(data);
		wall_pos(data);
		render_height_screen(data);
		put_ceiling(data, x);
		calc_color(data);
		draw_texture(data, x);
		put_floor(data, x);
		x++;
	}
}

int	calcul_image(t_data *data)
{
	update_position(data);
	if (data->player->change)
	{
		render_ray(data);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	}
	data->player->change = 0;
	return (0);
}

void	ray_casting(t_data *data)
{
	init_game(data);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &calcul_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &restore_key, data);
	
	mlx_loop(data->mlx->ptr);
	// data=data;
}