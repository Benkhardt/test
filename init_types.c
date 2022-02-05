/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:00:06 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/05 22:14:07 by dbenkhar         ###   ########.fr       */
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
