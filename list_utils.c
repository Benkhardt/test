/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:34:13 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/30 15:54:12 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	Descritpion:
//	Finding the most bottom element of map list.
//	Return:
//	Returning a t_map * to the most bottom element
//	of map list.
t_map	*find_last_elem(t_map *top)
{
	while (top->bot != NULL)
		top = top->bot;
	return (top);
}

//	Description:
//	creating a dqueued linked list, every elem containing
//	1 line 'y' of the map.
//	Return:
//	Returning the pointer to the top of the stacked elements
//	or returning NULL if the allocation fails.
t_map	*create_elem_ontop(void *str, t_map *top, int y)
{
	t_map	*rtn;

	rtn = malloc(sizeof(t_map));
	if (rtn == NULL)
		return (NULL);
	if (top != NULL)
		top->top = rtn;
	rtn->line_x = str;
	rtn->y = y;
	rtn->bot = top;
	rtn->top = NULL;
	rtn->valid = -1;
	return (rtn);
}

//	Description:
//	Prints out values of map list
//	Return: VOID
void	printlist(t_map *bot)
{
	while (bot != NULL)
	{
		ft_putstr_fd((char *)bot->line_x, 1);
		ft_putnbr_fd(bot->y, 1);
		ft_putchar_fd('\n', 1);
		bot = bot->top;
	}
}

// t_map	*init_map(int argc, char **argv, t_map *stack)
// {
// 	while (--argc > 0)
// 	{
// 		stack[1] = create_elem_ontop(ft_atoi(argv[argc]), stack[0]);
// 		if (stack[0] != NULL)
// 			stack[0]->top = stack[1];
// 		stack[0] = stack[1];
// 	}
// 	return (stack);
// }
