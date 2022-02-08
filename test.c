/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:04:19 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/08 21:26:36 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_all		*data;

	data = init_types();
	if (data == NULL)
		return (-1);
	data->mlx->ptr = mlx_init();
	if (data->mlx->ptr == NULL)
		return (-1);
	// Wall
	data->textures->wall->img = mlx_xpm_file_to_image(data->mlx->ptr, "./img/wall.xpm", &data->textures->wall->width, &data->textures->wall->height);
	if (data->textures->wall->img == NULL)
	{
		ft_putstr_fd("Error Wall\n", 1);
		return (-1);
	}
	data->mlx->win = mlx_new_window(data->mlx->ptr, 640, 480, "test");
	if (data->mlx->win == NULL)
	{
		ft_putstr_fd("Error window\n", 1);
		return (-1);
	}
	// put image to window
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->textures->wall->img, 0, 0);
	mlx_loop(data->mlx->ptr);
}
