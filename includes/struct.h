/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:38:45 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/28 14:46:08 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data			t_data;
typedef struct s_garbage		t_garbage;
typedef struct s_mlx			t_mlx;

struct	s_data
{ 
	t_garbage	*garb;
	char		*filename;
	t_mlx		*mlx;
	int			width;
	int			height;
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

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

#endif