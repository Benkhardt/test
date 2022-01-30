/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:27:27 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/30 15:52:43 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>  // perror error // Debug
# include <fcntl.h>
# include <string.h> // Debug

// define mlx stuff

# define SCREEN_X 640
# define SCREEN_Y 480
# define WIN_TITLE "so_long"

// define keyboard

# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13

//typedefs

// all
typedef struct s_all{
	struct s_map	*top_list;
	struct s_map	*bot_list;
	struct s_mlx	*mlx;
	// struct s_player	*player;
}	t_all;

// map data
typedef struct s_map{
	struct s_map	*top;
	void			*line_x;
	int				y;
	int				valid;
	struct s_map	*bot;
}	t_map;

// mlx data
typedef struct s_mlx{
	int				x;
	int				y;
	void			*ptr;
	void			*win;
}	t_mlx;

// player data
typedef struct s_player{
	int	pos_x;
	int	pos_y;
}	t_player;

// rototypes

t_all	*init_error_check(char **argv);

t_all	*world_init(t_all *data);

t_all	*init_types(t_all *data);

t_map	*create_elem_ontop(void *str, t_map *top, int y);

void	free_all(t_all *data);

void	free_list(t_map *top_list);

void	printlist(t_map *bot);

t_map	*find_last_elem(t_map *top);

int		check_validmap(t_map *bot);

#endif
