/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:21:34 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/30 14:31:53 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_map *top_list)
{
	t_map	*temp;

	temp = top_list->bot;
	while (top_list != NULL)
	{
		free(top_list->line_x);
		free(top_list);
		top_list = temp;
		if (top_list != NULL)
			temp = top_list->bot;
	}
}

void	free_all(t_all *data)
{
	free_list(data->top_list);
	free(data->mlx);
	free(data);
}
