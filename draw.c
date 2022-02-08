/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:19:03 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/08 23:25:27 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_wall(t_all *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx->ptr;
	win = data->mlx->win;
	img = data->textures->wall->img;
	mlx_put_image_to_window(mlx, win, img, x, y);
	return (63);
}

int	draw_field(t_all *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx->ptr;
	win = data->mlx->win;
	img = data->textures->zero->img;
	mlx_put_image_to_window(mlx, win, img, x, y);
	return (63);
}

int	draw_exit(t_all *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx->ptr;
	win = data->mlx->win;
	img = data->textures->exit->img;
	mlx_put_image_to_window(mlx, win, img, x, y);
	return (63);
}

int	draw_player(t_all *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx->ptr;
	win = data->mlx->win;
	img = data->textures->player->img;
	mlx_put_image_to_window(mlx, win, img, x, y);
	return (63);
}

int	draw_cons(t_all *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx->ptr;
	win = data->mlx->win;
	img = data->textures->cons->img;
	mlx_put_image_to_window(mlx, win, img, x, y);
	return (63);
}
