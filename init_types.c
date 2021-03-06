/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:00:06 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/09 08:27:17 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_all	*load_tex(t_all *data)
{
	data = load_wall(data);
	data = load_field(data);
	data = load_consum(data);
	data = load_player(data);
	data = load_exit(data);
	return (data);
}

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

static t_textures *init_text(void)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (textures == NULL)
		return (NULL);
	textures->wall = malloc(sizeof(t_wall));
	if (textures->wall == NULL)
		return (NULL);
	textures->cons = malloc(sizeof(t_cons));
	if (textures->cons == NULL)
		return (NULL);
	textures->zero = malloc(sizeof(t_zero));
	if (textures->zero == NULL)
		return (NULL);
	textures->exit = malloc(sizeof(t_exit));
	if (textures->exit == NULL)
		return (NULL);
	textures->player = malloc(sizeof(t_player));
	if (textures->player == NULL)
		return (NULL);
	return (textures);
}

t_all	*init_types(void)
{
	t_all	*data;

	data = malloc(sizeof(t_all));
	if (data == NULL)
		return (NULL);
	data->mlx = malloc(sizeof(t_mlx));
	if (data->mlx == NULL)
		return (NULL);
	data->textures = init_text();
	if (data->textures == NULL)
		return (NULL);
	data->flags = init_check();
	if (data->flags == NULL)
		return (NULL);
	data->coord = malloc(sizeof(t_coord));
	if (data->coord == NULL)
		return (NULL);
	data->top_list = NULL;
	data->bot_list = NULL;
	return (data);
}
