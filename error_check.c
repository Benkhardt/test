/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:06:26 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/05 22:18:26 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check for not allowed options in map
static int	check_y(char *build, char *allowed)
{
	int		i;

	i = -1;
	while (build[++i] != '\n')
		if (ft_memchr(allowed, (int)build[i], 5) == NULL)
			return (1);
	return (0);
}

// checks for rectangle and not allowed options in map
static t_all	*check_map(t_all *data)
{
	t_map	*temp;
	int		length;
	int		check;

	temp = data->bot_list;
	length = 0;
	check = 0;
	while (temp != NULL)
	{
		check = check_y((char *)temp->line_x->build, "01PCE");
		length = (int)ft_strlen(temp->line_x->build); 
		if (data->mlx->x != length || check)
			return (NULL);
		temp = temp->top;
	}
	return (data);
}

//	Description:
//	It checks for errors + finds map size
//	and stores it in t_mlx *data.
//	Return:
//	Returns t_mlx *data with size of map.
//	NULL if any error appears.
t_all	*error_check(t_all *data)
{
	data = check_map(data);
	if (data == NULL)
		return (NULL);
	data = check_validmap(data);
	if (data == NULL)
		return (NULL);
	return (data);
}
