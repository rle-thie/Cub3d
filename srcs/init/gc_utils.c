/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:49:28 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/28 14:48:50 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	ft_free_garb(t_garbage *garb)
{
	t_garbage	*tmp;

	while (garb && garb->next)
	{
		tmp = garb;
		if (garb && garb->ptr)
			free(garb->ptr);
		garb = garb->next;
		free(tmp);
	}
	if (garb)
	{
		free(garb->ptr);
		free(garb);
	}
}

void	remove_garb(void *ptr, t_data *data)
{
	t_garbage	*tmp;

	while (data->garb && data->garb->ptr != ptr)
		data->garb = data->garb->next;
	tmp = data->garb;
	if (data->garb && !data->garb->prev && !data->garb->next)
		return (free(tmp));
	if (data->garb && !data->garb->prev)
		data->garb->next->prev = NULL;
	else if (data->garb && !data->garb->next)
	{
		data->garb->prev->next = NULL;
		data->garb = data->garb->prev;
	}
	if (data->garb && data->garb->prev && data->garb->next)
	{
		data->garb->prev->next = data->garb->next;
		data->garb->next->prev = data->garb->prev;
	}
	if (data->garb && data->garb->next)
		data->garb = data->garb->next;
	free(tmp);
	while (data->garb && data->garb->prev)
		data->garb = data->garb->prev;
}

void	ft_free(void *ptr, t_data *data)
{
	free(ptr);
	remove_garb(ptr, data);
}