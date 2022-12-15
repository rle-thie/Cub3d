/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:40:03 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:20:47 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_texture_data(t_data *data, int n)
{
	if (data->raytracing->side == 0)
		data->raytracing->wall_x = data->player->y + data->raytracing->pwd
			* data->raytracing->dir_y;
	else
		data->raytracing->wall_x = data->player->x + data->raytracing->pwd
			* data->raytracing->dir_x;
	data->raytracing->wall_x -= floor((data->raytracing->wall_x));
	data->raytracing->text_x = (int)(data->raytracing->wall_x
			* (float)data->texture[n].w);
	if (data->raytracing->side == 0 && data->raytracing->dir_x > 0)
		data->raytracing->text_x = data->texture[n].w
			- data->raytracing->text_x - 1;
	if (data->raytracing->side == 1 && data->raytracing->dir_y < 0)
		data->raytracing->text_x = data->texture[n].w
			- data->raytracing->text_x - 1;
	data->raytracing->step = 1.0 * (float)data->texture[n].h
		/ data->raytracing->line_h;
	data->raytracing->text_pos = (data->raytracing->draw_start - data->height
			/ 2 + data->raytracing->line_h / 2) * data->raytracing->step;
}

void	calc_color(t_data *data)
{
	if (data->raytracing->side)
	{
		if (data->raytracing->dir_y < 0)
			data->raytracing->text_num = 2;
		else
			data->raytracing->text_num = 3;
	}
	else
	{
		if (data->raytracing->dir_x < 0)
			data->raytracing->text_num = 0;
		else
			data->raytracing->text_num = 1;
	}
	get_texture_data(data, data->raytracing->text_num);
}

void	put_floor(t_data *data, int x)
{
	int	y;

	y = data->raytracing->draw_end + 1;
	while (y < data->height)
	{
		data->mlx->addr[y * data->width + x] = data->f_color;
		y++;
	}
}

void	put_ceiling(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->raytracing->draw_start - 1)
	{
		data->mlx->addr[y * data->width + x] = data->c_color;
		y++;
	}
}

void	draw_texture(t_data *data, int x)
{
	int	y;

	y = data->raytracing->draw_start - 1;
	while (++y <= data->raytracing->draw_end)
	{
		data->raytracing->text_y = (int)data->raytracing->text_pos
			& (data->texture[data->raytracing->text_num].h - 1);
		data->raytracing->text_pos += data->raytracing->step;
		if (y < data->height && x < data->width)
		{
			data->mlx->addr[y * data->width + x] = \
			data->texture[data->raytracing->text_num].\
			addr[data->raytracing->text_y
				* data->texture[data->raytracing->text_num].w
				+ data->raytracing->text_x];
		}
	}
}
