/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:06:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/30 15:52:11 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_all	*init_types(t_all *data)
{
	data = malloc(sizeof(t_all));
	if (data == NULL)
		return (NULL);
	data->mlx = malloc(sizeof(t_mlx));
	if (data->mlx == NULL)
	{
		free(data);
		return (NULL);
	}
	data->top_list = NULL;
	return (data);
}

static int	check_y(char *build, char *allowed)
{
	int		i;
	size_t	n;

	i = -1;
	n = ft_strlen(allowed);
	while (build[++i] != '\0' && build[i] != '\n')
		if (ft_memchr(allowed, (int)build[i], n) == NULL)
			return (1);
	return (0);
}

static t_all	*check_map(t_all *data, int fd)
{
	char	*build;

	data->mlx->y = 0;
	build = get_next_line(fd);
	if (build == NULL)
	{
		free(data);
		return (NULL);
	}
	data->mlx->x = ft_strlen(build);
	while (build != NULL)
	{
		if (data->mlx->x != (int)ft_strlen(build) || check_y(build, "01PCE"))
		{
			free(data);
			free(build);
			return (NULL);
		}
		data->top_list = create_elem_ontop(build, data->top_list, data->mlx->y);
		build = get_next_line(fd);
		data->mlx->y++;
	}
	return (data);
}

//	Description:
//	It checks for errors + finds map size
//	and stores it in t_mlx *data.
//	Return:
//	Returns t_mlx *data with size of map.
//	NULL if any error appears.
t_all	*init_error_check(char **argv)
{
	int		fd;
	t_all	*data;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	data = NULL;
	data = init_types(data);
	data = check_map(data, fd);
	if (data == NULL)
		return (NULL);
	return (data);
}
