/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:53:57 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/30 15:56:54 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	Description:
//	Meant to check only for first and last line of map.
//	Return:
//	Returning 1 if valid 0 if not
static int	check_easy_lines(t_map *bot)
{

}

//	Description:
//	checking either the map is valid or not.
//	Return:
//	Returning int 1 if valid 0 if not.
int	check_validmap(t_map *bot)
{
	int		i;
	t_map	*temp;
	char	*line;

	temp = bot;
	i = 0;
	if (bot != NULL)
		line = (char *)bot->line_x;
	
}
