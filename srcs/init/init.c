/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:43:15 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/27 01:14:54 by rle-thie         ###   ########.fr       */
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
	data->filename = NULL;
	return (data);
}

t_data	*init(char *filename)
{
	t_data *data;

	data = init_data();
	data->filename = ft_strdup(filename, data);
	printf("%s\n", data->filename);
	return (data);
}