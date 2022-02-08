/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:04:19 by dbenkhar          #+#    #+#             */
/*   Updated: 2022/02/07 13:58:54 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx_ptr;
	void	*img;
	void	*mlx_win;
	int		img_width;
	int		img_height;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (-1);
	img = mlx_xpm_file_to_image(mlx_ptr, "./img/wall.xpm", &img_width, &img_height);
	if (img == NULL)
	{
		ft_putstr_fd("Error1\n", 1);
		return (-1);
	}
	mlx_win = mlx_new_window(mlx_ptr, 640, 480, "test");
	if (mlx_win == NULL)
		return (-1);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 0, 0);
	mlx_loop(mlx_ptr);
}
