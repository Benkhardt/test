/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:25:57 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/09 08:26:51 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static t_mlx	*build_map(t_mlx *data)
// {

// }

t_all	*world_init(t_all *data)
{
	data->mlx->ptr = mlx_init();
	if (data->mlx->ptr == NULL)
	{
		free(data->mlx->ptr);
		return (NULL);
	}
	data->mlx->win = mlx_new_window(data->mlx->ptr, (data->mlx->x - 1) * 63, data->mlx->y * 63, WIN_TITLE);
	if (data->mlx->win == NULL)
	{
		free(data->mlx->win);
		return (NULL);
	}
	data = load_tex(data);
	data = build_map(data);
	return (data);
}
