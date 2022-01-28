/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:55:40 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/28 15:49:46 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_y(char *build, char *allowed)
{
	int	i;

	i = 0;
	while (build[i] != '\0')
	{

	}
}

t_mlx	*map_init(t_mlx *data, char *map)
{
	int		fd;
	int		get_y;
	int		get_x;
	char	*build;

	fd = open(map, O_RDONLY);
	get_y = 0;
	build = get_next_line(fd);
	get_x = ft_strlen(build);
	while (build != NULL)
	{
		if (get_x != ft_strlen(build) || check_y(build, "01PCE"))
			return (NULL);
		build = get_next_line(fd);
		get_y++;
	}
	free(build);
}

int	main(int argc, char **argv)
{
	t_mlx		*data;
	t_player	player;
	int			error;

	error = error_manage();
	data->ptr = mlx_init();
	if (data->ptr == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	data = map_init(&data, argv[1]);
	if (data == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	data->win = mlx_new_window(data->ptr, data->x, data->y, WIN_TITLE);
	mlx_loop(data->ptr);
}
