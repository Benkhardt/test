/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:21:34 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/02 22:24:29 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_map *top_list)
{
	t_map	*temp;

	temp = top_list->bot;
	while (top_list != NULL)
	{
		free(top_list->line_x->build);
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
	if (data->mlx != NULL)
		free(data->mlx);
	if (data->flags != NULL)
		free(data->flags);
	if (data->gnl != NULL)
		free(data->gnl);
	if (data != NULL)
		free(data);
}
