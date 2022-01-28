/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:27:27 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/01/27 16:05:15 by dbenkhar         ###   ########.fr       */
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

# define SCREEN_X 640
# define SCREEN_Y 480
# define NAME_PROG "so_long"

// typedefs

typedef struct s_mlx{
	int		x;
	int		y;
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_player{
	int	pos_x;
	int	pos_y;
}	t_player;

// prototypes

#endif