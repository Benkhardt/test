/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:27:27 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/02 21:24:39 by dbenkhar         ###   ########.fr       */
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
	struct s_check	*flags;
	struct s_mlx	*mlx;
	// struct s_player	*player;
}	t_all;

// map data elements (columns containing each row from gnl)
typedef struct	s_map{
	struct s_map	*top;
	void			*line_x;
	int				y;
	int				valid;
	struct s_map	*bot;
}	t_map;

// mlx data
typedef struct	s_mlx{
	int				x;
	int				y;
	void			*ptr;
	void			*win;
}	t_mlx;

typedef struct	s_check{
	unsigned int	p; // has to be 1
	unsigned int	c; // has to be minimum 1
	unsigned int	e; // has to be 1
	// unsigned int	zero; // has to be minimum 1
}	t_check;

// player data
typedef struct	s_player{
	int	pos_x;
	int	pos_y;
}	t_player;

// rototypes

t_all	*error_check(char **argv, t_all *data);

t_all	*world_init(t_all *data);

t_all	*init_types(void);

t_map	*create_elem_ontop(void *str, t_map *top, int y);

void	free_all(t_all *data);

void	free_list(t_map *top_list);

void	printlist(t_map *bot);

t_map	*find_last_elem(t_map *top);

t_all	*check_validmap(t_all *data);

#endif
