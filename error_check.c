/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:06:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/30 12:09:49 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static t_mlx	*check_map(t_mlx *data, int fd)
{
	char	*build;

	data->y = 0;
	build = get_next_line(fd);
	if (build == NULL)
	{
		free(data);
		return (NULL);
	}
	data->x = ft_strlen(build);
	while (build != NULL)
	{
		if (data->x != (int)ft_strlen(build) || check_y(build, "01PCE", data->y))
		{
			free(data);
			free(build);
			return (NULL);
		}
		free(build);
		build = get_next_line(fd);
		data->y++;
	}
	return (data);
}

//	Description:
//	It checks for errors + finds map size
//	and stores it in t_mlx *data.
//	Return:
//	Returns t_mlx *data with size of map.
//	NULL if any error appears.
t_mlx	*error_check(int argc, char **argv)
{
	int		fd;
	t_mlx	*data;

	if (argc != 2)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	data = malloc(sizeof(t_mlx));
	if (data == NULL)
		return (NULL);
	data = check_map(data, fd);
	if (data == NULL)
		return (NULL);
	return (data);
}
