/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:31:42 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/28 14:50:27 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	// clear_mlx(data);
	ft_exit_message(msg, data, 1);
	free_all(data);
	exit(value);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	ac = ac;
	av = av;
	env = env;
	if (ac != 2)
		return (0);
	data = init(av[1]);
	data = data;
	// parsing
	ray_casting(data);
	free_all(data);
	return (0);
}