/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:27:27 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/13 23:53:36 by dbenkhar         ###   ########.fr       */
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

// # define K_ESC 
# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13

//typedefs

// all
typedef struct	s_all{
	struct s_map		*top_list;
	struct s_map		*bot_list;
	struct s_check		*flags;
	struct s_mlx		*mlx;
	struct s_gnl		*gnl;
	struct s_data		*pic;
	struct s_textures	*textures;
	struct s_coord		*coord;
}	t_all;

/*
** texture data structure to pre load images
*/
typedef struct	s_textures{
	struct s_wall	*wall;
	struct s_player	*player;
	struct s_cons	*cons;
	struct s_zero	*zero;
	struct s_exit	*exit;
}	t_textures;

// save wall texture
typedef struct	s_wall{
	void	*img;
	int		width;
	int		height;
}	t_wall;

// save consumables texture
typedef struct	s_cons{
	void	*img;
	int		width;
	int		height;
}	t_cons;

// save zero texture(fields to move through)
typedef struct	s_zero{
	void	*img;
	int		width;
	int		height;
}	t_zero;

// save exit texture
typedef struct	s_exit{
	void	*img;
	int		width;
	int		height;
}	t_exit;

// save player texture
typedef struct s_player{
	void	*img;
	int		width;
	int		height;
}	t_player;

// struct to build map
typedef struct	s_coord{
	int	x;
	int	y;
}	t_coord;

// map data elements (columns containing each row from gnl)
typedef struct	s_map{
	struct s_map	*top;
	struct s_gnl	*line_x;
	int				y;
	int				valid;
	struct s_map	*bot;
}	t_map;

// gnl pointers
typedef struct	s_gnl{
	void	*build;
	void	*stat;
}	t_gnl;

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

// rototypes

t_all	*error_check(t_all *data);

t_gnl	*get_next_line(int fd);

t_all	*world_init(t_all *data);

t_all	*init_types(void);

t_map	*create_elem_ontop(void *str, t_map *top, int y);

void	free_all(t_all *data);

void	free_list(t_map *top_list);

void	printlist(t_map *bot);

void	key_events(t_all *data);

t_map	*find_last_elem(t_map *top);

t_all	*check_validmap(t_all *data);

t_all	*read_map(t_all *data, char *argv);

t_all	*build_map(t_all *data);

t_all	*load_tex(t_all *data);

t_all	*load_wall(t_all *data);

t_all	*load_field(t_all *data);

t_all	*load_consum(t_all *data);

t_all	*load_exit(t_all *data);

t_all	*load_player(t_all *data);

int		draw_wall(t_all *data, int x, int y);

int		draw_field(t_all *data, int x, int y);

int		draw_exit(t_all *data, int x, int y);

int		draw_player(t_all *data, int x, int y);

int		draw_cons(t_all *data, int x, int y);

#endif
