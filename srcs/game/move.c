/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:20:02 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:28:44 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player->x + (data->player->dir_x
				* data->move_speed))][(int)data->player->y] != '1')
	{
		data->player->x += data->player->dir_x * data->move_speed;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		+ data->player->dir_y * data->move_speed)] != '1')
	{
		data->player->y += data->player->dir_y * data->move_speed;
		data->player->change = 1;
	}
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player->x - data->player->dir_x
			* data->move_speed)][(int)data->player->y] != '1')
	{
		data->player->x -= data->player->dir_x * data->move_speed;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		- data->player->dir_y * data->move_speed)] != '1')
	{
		data->player->y -= data->player->dir_y * data->move_speed;
		data->player->change = 1;
	}
}

void	move_right(t_data *data)
{
	if (data->map[(int)(data->player->x + (data->player->dir_y
				* data->move_speed))][(int)data->player->y] != '1')
	{
		data->player->x += data->player->dir_y * data->move_speed;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		- (data->player->dir_x * data->move_speed))] != '1')
	{
		data->player->y -= data->player->dir_x * data->move_speed;
		data->player->change = 1;
	}
}

void	move_left(t_data *data)
{
	if (data->map[(int)(data->player->x - data->player->dir_y
			* data->move_speed)][(int)data->player->y] != '1')
	{
		data->player->x -= data->player->dir_y * data->move_speed;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		+ data->player->dir_x * data->move_speed)] != '1')
	{
		data->player->y += data->player->dir_x * data->move_speed;
		data->player->change = 1;
	}
}

void	rotate_right(t_data *data)
{
	double	old_plane_x;

	old_plane_x = data->raytracing->plane_x;
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->player->dir_x = data->player->dir_x
		* cos(-data->rotate_speed) - data->player->dir_y
		* sin(-data->rotate_speed);
	data->player->dir_y = data->player->old_dx
		* sin(-data->rotate_speed) + data->player->dir_y
		* cos(-data->rotate_speed);
	data->raytracing->plane_x = data->raytracing->plane_x
		* cos(-data->rotate_speed) - data->raytracing->plane_y
		* sin(-data->rotate_speed);
	data->raytracing->plane_y = old_plane_x
		* sin(-data->rotate_speed) + data->raytracing->plane_y
		* cos(-data->rotate_speed);
	data->player->change = 1;
}
