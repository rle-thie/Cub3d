/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:43:15 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/07 11:23:38 by rle-thie         ###   ########.fr       */
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

void	init_raytracing_utils(t_data *data)
{
	data->raytracing->hit = 0;
	data->raytracing->side = 0;
	data->raytracing->side = 0;
	data->raytracing->map_x = 0;
	data->raytracing->map_y = 0;
	data->raytracing->step_x = 0;
	data->raytracing->step_y = 0;
	data->raytracing->line_h = 0;
	data->raytracing->text_x = 0;
	data->raytracing->text_y = 0;
	data->raytracing->text_num = 0;
	data->raytracing->draw_end = 0;
	data->raytracing->draw_start = 0;
}

void	init_raytracing(t_data *data)
{
	data->raytracing->pwd = 0;
	data->raytracing->ddy = 0;
	data->raytracing->ddx = 0;
	data->raytracing->sdy = 0;
	data->raytracing->sdx = 0;
	data->raytracing->step = 0;
	data->raytracing->dir_x = 0;
	data->raytracing->dir_y = 0;
	data->raytracing->wall_x = 0;
	data->raytracing->text_pos = 0;
	data->raytracing->plane_x = 0;
	data->raytracing->plane_y = 0;
	data->raytracing->camera_x = 0;
	init_raytracing_utils(data);
}

void	init_texture(t_data *data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		data->texture[i].h = 0;
		data->texture[i].w = 0;
		data->texture[i].bpp = 0;
		data->texture[i].endian = 0;
		data->texture[i].line_length = 0;
		data->texture[i].addr = NULL;
		data->texture[i].img = NULL;
		data->texture[i].path = NULL;
		i++;
	}
}

void	initialise_struct(t_data *data)
{
	init_mlx(data);
	init_key(data);
	init_player(data);
	init_raytracing(data);
	init_texture(data);
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
	data->c_color = 0;
	data->f_color = 0;
	data->filename = ft_strdup(filename, data);
	printf("%s\n", data->filename);
	return (data);
}