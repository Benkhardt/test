/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:13:16 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/09 08:26:02 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_all	*load_exit(t_all *data)
{
	t_exit	*exit;
	void	*mlx_ptr;

	exit = data->textures->exit;
	mlx_ptr = data->mlx->ptr;
	exit->img = mlx_xpm_file_to_image(mlx_ptr, "./img/exit.xpm", &exit->width, &exit->height);
	return (data);
}

t_all	*load_player(t_all *data)
{
	t_player	*player;
	void		*mlx_ptr;

	player = data->textures->player;
	mlx_ptr = data->mlx->ptr;
	player->img = mlx_xpm_file_to_image(mlx_ptr, "./img/player.xpm", &player->width, &player->height);
	return (data);
}

t_all	*load_field(t_all *data)
{
	t_zero	*field;
	void	*mlx_ptr;

	field = data->textures->zero;
	mlx_ptr = data->mlx->ptr;
	field->img = mlx_xpm_file_to_image(mlx_ptr, "./img/floor.xpm", &field->width, &field->height);
	return (data);
}

t_all	*load_wall(t_all *data)
{
	t_wall	*wall;
	void	*mlx_ptr;

	wall = data->textures->wall;
	mlx_ptr = data->mlx->ptr;
	wall->img = mlx_xpm_file_to_image(mlx_ptr, "./img/wall.xpm", &wall->width, &wall->height);
	return (data);
}

t_all	*load_consum(t_all *data)
{
	t_cons	*consum;
	void	*mlx_ptr;

	consum = data->textures->cons;
	mlx_ptr = data->mlx->ptr;
	consum->img = mlx_xpm_file_to_image(mlx_ptr, "./img/coll.xpm", &consum->width, &consum->height);
	return (data);
}
