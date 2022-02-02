/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:53:57 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/02 22:34:42 by dbenkhar         ###   ########.fr       */
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

static t_check	*check_line(char *line, t_check *flags)
{
	unsigned int	i;

	i = 0;
	if (line[0] != '1')
		return (NULL);
	while (line[++i] != '\n')
	{
		if (line[i] == 'P')
			flags->p++;
		else if (line[i] == 'C')
			flags->c++;
		else if (line[i] == 'E')
			flags->e++;
		else if (line[i] != '1' && line[i] != '0')
			return (NULL);
	}
	if (line[i - 1] != '1')
			return (NULL);
	return (flags);
}

//	Description:
//	Meant to check only for first and last line of map.
//	Return:
//	Returning 0 if valid 1 if not
static int	check_easy(t_map *bot)
{
	int		i;
	char	*conv;

	i = -1;
	conv = (char *)bot->line_x;
	while (conv[++i] != '\n')
		if (ft_memchr("1", conv[i], 1) == NULL)
			return (1);
	return (0);
}

//	Description:
//	checking either the map is valid or not.
//	Return:
//	Returning t_all * if valid NULL if not.
t_all	*check_validmap(t_all *data)
{
	t_map	*temp;

	data->flags = init_check();
	if (data->flags == NULL)
		return (NULL);
		data->bot_list = find_last_elem(data->top_list);
	if (check_easy(data->bot_list) || check_easy(data->top_list))
		return (NULL);
	temp = data->bot_list->top;
	while (temp->top != NULL)
	{
		data->flags = check_line((char *)temp->line_x, data->flags);
		if (data->flags == NULL)
			return (NULL);
		temp = temp->top;
	}
	if (data->flags->c >= 1
		&& data->flags->e >= 1 && data->flags->p >= 1)
		return (data);
	else
		return (NULL);
}
