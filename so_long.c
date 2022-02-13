/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:55:40 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/14 00:41:38 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_all	*data;
	t_all	*store;
	// t_player	player;

	if (argc != 2)
	{
		ft_putstr_fd("Error1\n", 1);
		return (-1);
	}
	data = init_types();
	if (data == NULL)
	{
		ft_putstr_fd("Error2\n", 1);
		return (-1);
	}
	store = data;
	data = read_map(data, argv[1]);
	if (data == NULL)
	{
		free_all(store);
		ft_putstr_fd("Error4\n", 1);
		return (-1);
	}
	data = error_check(data);
	if (data == NULL)
	{
		free_all(store);
		ft_putstr_fd("Error3\n", 1);
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
	// data->bot_list = find_last_elem(data->top_list);
	// ft_putnbr_fd(data->bot_list->y, 1);
	// ft_putchar_fd('\n', 1);
	printlist(data->bot_list);
	data = world_init(data);
	if (data == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	key_events(data);
	mlx_loop(data->mlx->ptr);
}
