/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:06:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/02 22:11:42 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_check	*init_check(void)
{
	t_check	*flags;

	flags = malloc(sizeof(t_check));
	if (flags == NULL)
		return (NULL);
	flags->c = 0;
	flags->e = 0;
	flags->p = 0;
	return (flags);
}

t_all	*init_types(void)
{
	t_all	*data;
	
	data = malloc(sizeof(t_all));
	if (data == NULL)
		return (NULL);
	data->mlx = malloc(sizeof(t_mlx));
	if (data->mlx == NULL)
	{
		free(data);
		return (NULL);
	}
	data->flags = init_check();
	if (data->flags == NULL)
	{
		free(data->mlx);
		free(data);
		return (NULL);
	}
	data->top_list = NULL;
	data->bot_list = NULL;
	return (data);
}

static int	check_y(char *build, char *allowed)
{
	int		i;

	i = -1;
	while (build[++i] != '\n')
		if (ft_memchr(allowed, (int)build[i], 5) == NULL)
			return (1);
	return (0);
}

static t_all	*check_map(t_all *data, int fd)
{
	data->mlx->y = 0;
	data->gnl = get_next_line(fd);
	if (data->gnl->build == NULL)
		return (NULL);
	data->mlx->x = ft_strlen(data->gnl->build);
	while (data->gnl->build != NULL)
	{
		if (data->mlx->x != (int)ft_strlen((char *)data->gnl->build) || check_y((char *)data->gnl->build, "01PCE"))
		{
			free(data->gnl->build);
			free(data->gnl->stat);
			free(data->gnl);
			return (NULL);
		}	
		data->top_list = create_elem_ontop(data->gnl, data->top_list, data->mlx->y);
		data->gnl = get_next_line(fd);
		data->mlx->y++;
	}
	free(data->gnl);
	return (data);
}

//	Description:
//	It checks for errors + finds map size
//	and stores it in t_mlx *data.
//	Return:
//	Returns t_mlx *data with size of map.
//	NULL if any error appears.
t_all	*error_check(char **argv, t_all *data)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	data = check_map(data, fd);
	if (data == NULL)
		return (NULL);
	data = check_validmap(data);
	if (data == NULL)
		return (NULL);
	return (data);
}
