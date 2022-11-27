/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:47:45 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/27 00:49:36 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	ft_garb_addback(t_data *data, t_garbage *new)
{
	while (data->garb->next)
		data->garb = data->garb->next;
	new->prev = data->garb;
	data->garb->next = new;
	while (data->garb->prev)
		data->garb = data->garb->prev;
}

t_garbage	*ft_garb_lstnew(void *ptr, t_data *data)
{
	t_garbage	*new;

	new = malloc(sizeof(*new));
	if (!new)
	{
		free_all(data);
		printf("Error\ncub3d: malloc error\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

void	*ft_malloc(size_t size, t_data *data)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		free_all(data);
		printf("Error\ncub3d: malloc error\n");
		exit(EXIT_FAILURE);
	}
	if (data->garb && data->garb->ptr)
		ft_garb_addback(data, ft_garb_lstnew(ptr, data));
	else if (data->garb)
	{
		data->garb->prev = NULL;
		data->garb->ptr = ptr;
		data->garb->next = NULL;
	}
	return (ptr);
}

void	*ft_calloc(size_t size, t_data *data)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		free_all(data);
		printf("Error\ncub3d: malloc error\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(ptr, size);
	if (data->garb && data->garb->ptr)
		ft_garb_addback(data, ft_garb_lstnew(ptr, data));
	else if (data->garb)
	{
		data->garb->prev = NULL;
		data->garb->ptr = ptr;
		data->garb->next = NULL;
	}
	return (ptr);
}
