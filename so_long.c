/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:55:40 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/29 11:39:26 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		*data;
	// t_player	player;

	data = error_check(argc, argv);
	if (data == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	// data->ptr = mlx_init();
	// if (data->ptr == NULL)
	// {
	// 	free(data);
	// 	ft_putstr_fd("Error\n", 1);
	// 	return (-1);
	// }
	// data->win = mlx_new_window(data->ptr, data->x, data->y, WIN_TITLE);
	// if (data->win == NULL)
	// {
	// 	ft_putstr_fd("Error\n", 1);
	// 	return (-1);
	// }
	data = world_init(data);
	if (data == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	mlx_loop(data->ptr);
}
