/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:31:42 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/27 18:58:02 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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