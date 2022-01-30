/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:25:57 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/29 11:59:29 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static t_mlx	*build_map(t_mlx *data)
// {

// }

t_mlx	*world_init(t_mlx *data)
{
	data->ptr = mlx_init();
	if (data->ptr == NULL)
	{
		free(data);
		return (NULL);
	}
	data->win = mlx_new_window(data->ptr, (data->x - 1) * 63, data->y * 63, WIN_TITLE);
	if (data->win == NULL)
	{
		free(data);
		return (NULL);
	}
	// data = build_map(data);
	return (data);
}