/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:16:47 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/05 21:58:06 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_all	*read_map(t_all *data, char	*argv)
{
	int	fd;

	data->mlx->y = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data->gnl = get_next_line(fd);
	if (data->gnl->build == NULL)
		return (NULL);
	data->mlx->x = ft_strlen(data->gnl->build);
	while (data->gnl->build != NULL)
	{
		data->top_list = create_elem_ontop(data->gnl, data->top_list, data->mlx->y);
		data->gnl = get_next_line(fd);
		data->mlx->y++;
	}
	free(data->gnl);
	data->bot_list = find_last_elem(data->top_list);
	return (data);
}

/*
**	old state backup
*/

// t_all	*read_map(t_all *data, int fd)
// {
// 	data->mlx->y = 0;
// 	data->gnl = get_next_line(fd);
// 	if (data->gnl->build == NULL)
// 		return (NULL);
// 	data->mlx->x = ft_strlen(data->gnl->build);
// 	while (data->gnl->build != NULL)
// 	{
// 		if (data->mlx->x != (int)ft_strlen((char *)data->gnl->build) || check_y((char *)data->gnl->build, "01PCE")) // take this line
// 		{
// 			free(data->gnl->build);
// 			free(data->gnl->stat);
// 			free(data->gnl);
// 			return (NULL);
// 		}
// 		data->top_list = create_elem_ontop(data->gnl, data->top_list, data->mlx->y);
// 		data->gnl = get_next_line(fd);
// 		data->mlx->y++;
// 	}
// 	free(data->gnl);
// 	return (data);
// }