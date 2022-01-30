/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:27:27 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/29 11:32:21 by dbenkhar         ###   ########.fr       */
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

// typedefs

typedef struct s_mlx{
	int		x;
	int		y;
	// int		error;
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_player{
	int	pos_x;
	int	pos_y;
}	t_player;

// prototypes

t_mlx	*error_check(int argc, char **argv);
t_mlx	*world_init(t_mlx *data);

#endif