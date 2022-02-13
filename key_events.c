/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:01:47 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/14 00:39:47 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_game(int keycode, t_all *data)
{
	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	return (keycode);
}

void	key_events(t_all *data)
{
	mlx_hook(data->mlx->win, 2, 1L<<0, close_game, data);
}
