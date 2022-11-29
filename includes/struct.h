/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:38:45 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/29 09:43:17 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data			t_data;
typedef struct s_garbage		t_garbage;
typedef struct s_mlx			t_mlx;
typedef	struct s_key			t_key;
typedef struct s_player			t_player;
typedef struct s_raytracing		t_raytracing;

struct	s_data
{ 
	t_garbage	*garb;
	char		*filename;
	t_mlx		*mlx;
	int			width;
	int			height;
	t_key		*key;
	t_player	*player;
	float		move_speed;
	float		rotate_speed;
	t_raytracing	*raytracing;
};

struct s_key
{
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	key_lr;
	int	key_la;
};

struct s_player
{
	int		change;
	char	dir;
	float	x;
	float	y;
	float	old_x;
	float	old_y;
	float	dir_x;
	float	dir_y;
	float	old_dx;
	float	old_dy;
};

struct s_mlx
{
	int		bpp;
	int		line_length;
	int		endian;
	int		*addr;
	void	*ptr;
	void	*win;
	void	*img;
};

struct s_raytracing
{
	float	pwd;
	float	ddy;
	float	ddx;
	float	sdy;
	float	sdx;
	float	step;
	float	dir_x;
	float	dir_y;
	float	wall_x;
	float	text_pos;
	float	plane_x;
	float	plane_y;
	float	camera_x;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		line_h;
	int		text_x;
	int		text_y;
	int		text_num;
	int		draw_end;
	int		draw_start;
};

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

#endif