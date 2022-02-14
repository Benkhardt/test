/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:01:47 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/14 00:59:03 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_all *data)
{
	if (data == NULL)
		return (-1);
	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	mlx_destroy_display(data->mlx->ptr);
	free_all(data);
	exit(0);
}

static int	key_hook(int keycode, t_all *data)
{
	if (keycode == K_ESC)
		close_window(data);
	else if (keycode == K_A)
		move_left(data);
	else if (keycode == K_S)
		move_bottom(data);
	else if (keycode == K_D)
		move_right(data);
	else if (keycode == K_W)
		move_up(data);
	return (0);
}

// static int	close_game(int keycode, t_all *data)
// {
// 	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
// 	return (keycode);
// }

void	key_events(t_all *data)
{
	mlx_hook(data->mlx->win, 2, 1L<<0, key_hook, data);
}
