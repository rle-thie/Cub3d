/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:58:41 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:51:46 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	make_img(t_data *data, int x)
{
	ray_dir(data, x);
	render_steps(data);
	wall_pos(data);
	render_height_screen(data);
}

void	draw_img(t_data *data, int x)
{
	put_ceiling(data, x);
	calc_color(data);
	draw_texture(data, x);
	put_floor(data, x);
}

void	render_ray(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		make_img(data, x);
		draw_img(data, x);
		x++;
	}
}

int	game(t_data *data)
{
	update_position(data);
	if (data->player->change)
	{
		render_ray(data);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win,
			data->mlx->img, 0, 0);
	}
	data->player->change = 0;
	return (0);
}

void	ray_casting(t_data *data)
{
	init_game(data);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &game, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &restore_key, data);
	mlx_loop(data->mlx->ptr);
}
