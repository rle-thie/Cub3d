/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:31:42 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 14:38:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_exit(t_data *data)
{
	int	i;

	i = -1;
	if (data->mlx->ptr && data->mlx->win)
	{
		mlx_clear_window(data->mlx->ptr, data->mlx->win);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	}
	if (data->mlx->ptr && data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	while (++i < 4)
	{
		if (data->texture[i].img)
			mlx_destroy_image(data->mlx->ptr, data->texture[i].img);
	}
	if (data->mlx->ptr)
	{
		mlx_destroy_display(data->mlx->ptr);
		free(data->mlx->ptr);
	}
}

int	ft_exit_esc(t_data *data)
{
	mlx_exit(data);
	free_all(data);
	exit(0);
}

void	ft_exit_message(char *msg, t_data *data, int value)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit(value);
}

int	ft_free_exit(char *msg, int value, t_data *data)
{
	mlx_exit(data);
	ft_exit_message(msg, data, 1);
	free_all(data);
	exit(value);
}

void	debug_fct(t_data *data)
{
	int	i;

	i = 0;
	printf("texture NO : %s\n", data->texture[0].path);
	printf("texture SO : %s\n", data->texture[1].path);
	printf("texture WE : %s\n", data->texture[2].path);
	printf("texture EA : \'%p\'\n", data->texture[3].path);
	printf("color C : %d\n", data->c_color);
	printf("color C expected : %d\n", convert_trgb(0, 15, 99, 153));
	printf("color F : %d\n", data->f_color);
	printf("color F expected : \'%d\'\n", convert_trgb(0, 142, 95, 39));
	if (data->map)
	{
		while (data->map[i])
		{
			printf("%s", data->map[i]);
			i++;
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	ac = ac;
	av = av;
	env = env;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong number of argument.\n", 2);
		return (0);
	}
	data = init(av[1]);
	parsing(data);
	debug_fct(data);
	// if (!parsing())
		// ft_free_exit("Error\nParsing error", 1, data)
	ray_casting(data);
	free_all(data);
	return (0);
}
