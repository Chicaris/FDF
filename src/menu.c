/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:04:25 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 11:30:43 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		show_line(t_ptr self, int y, char *str)
{
	int		i;

	i = 0;
	while (i <= WIDTH)
	{
		mlx_string_put(self.mlx_ptr, self.win_ptr, i, y, YELLOW, str);
		i++;
	}
}

static void		show_viseur(t_ptr self)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		mlx_pixel_put(self.mlx_ptr, self.win_ptr, self.x_center + i,
				self.y_center, YELLOW);
		mlx_pixel_put(self.mlx_ptr, self.win_ptr, self.x_center - i,
				self.y_center, YELLOW);
		mlx_pixel_put(self.mlx_ptr, self.win_ptr, self.x_center,
				self.y_center + i, YELLOW);
		mlx_pixel_put(self.mlx_ptr, self.win_ptr, self.x_center,
				self.y_center - i, YELLOW);
		i++;
	}
}

void			show_menu(t_game *game)
{
	show_line(game->ptr, 0, "=");
	mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, WIDTH / 2 - 60,
			50, YELLOW, "Project : FDF");
	mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, 10, LENGTH - 185,
			YELLOW, "Press ESC to exit");
	mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, 10, LENGTH - 105,
			YELLOW, "Use WSAD to move the camera in the focal plan");
	mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, 10, LENGTH - 65,
			YELLOW, "Press P to change projection");
	mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, 10, LENGTH - 85,
			YELLOW, "Press C to change color");
	mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, 10, LENGTH - 45,
			YELLOW, "Use the mouse or the arrow to rotate the camera");
	mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, WIDTH - 200,
			LENGTH - 50, YELLOW, "By Bruno Cornil");
	show_line(game->ptr, 100, "=");
	show_line(game->ptr, LENGTH - 200, "=");
	if (game->camera.projection == CAMERA_PROJ)
		mlx_string_put(game->ptr.mlx_ptr, game->ptr.win_ptr, 10, LENGTH - 125,
				YELLOW, "Use the scroll or + and - to move ");
	show_viseur(game->ptr);
}
