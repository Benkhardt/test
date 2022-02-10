/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:52:51 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/10 20:05:52 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_x(t_all *data, int x, int y, t_map *temp)
{
	char	*line;
	int		i;

	line = (char *)temp->line_x->build;
	i = -1;
	// ft_putstr_fd(temp->line_x->build, 1);
	// ft_putnbr_fd(temp->y, 1);
	// ft_putchar_fd('\n', 1);
	while (line[++i] != '\n' || line[++i] != '\0')
	{
		if (line[i] == '1')
			x += draw_wall(data, x, y);
		else if (line[i] == '0')
			x += draw_field(data, x, y);
		else if (line[i] == 'E')
			x += draw_exit(data, x, y);
		else if (line[i] == 'P')
			x += draw_player(data, x, y);
		else if (line[i] == 'C')
			x += draw_cons(data, x, y);
	}
}

t_all	*build_map(t_all *data)
{
	t_map	*temp;

	data->coord->x = 0;
	data->coord->y = 0;
	temp = data->bot_list;
	while (temp != NULL)
	{
		draw_x(data, data->coord->x, data->coord->y, temp);
		data->coord->y += 63;
		temp = temp->top;
	}
	return (data);
}
