/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:55:40 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/27 03:17:29 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx	data;

	data.ptr = NULL;
	data.win = NULL;
	data.x = SCREEN_X;
	data.y = SCREEN_Y;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, data.x, data.y, NAME_PROG);
	mlx_loop(data.ptr);
}
