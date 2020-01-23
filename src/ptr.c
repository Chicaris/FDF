/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:47:59 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 10:48:35 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_bool		init_ptr(t_game *game)
{
	t_ptr	self;

	self.title = "FDF";
	self.x_center = WIDTH / 2;
	self.y_center = LENGTH / 2;
	self.x_min = -self.x_center;
	self.x_max = self.x_center;
	self.y_min = -self.y_center + 200;
	self.y_max = self.y_center - 120;
	if (!(self.mlx_ptr = mlx_init()))
		print_error(game, ERROR_MLX_INIT);
	if (!(self.win_ptr = mlx_new_window(self.mlx_ptr,
					WIDTH, LENGTH, self.title)))
		print_error(game, ERROR_NEW_WIN);
	game->ptr = self;
	return (true);
}

void		mainloop(t_game *game)
{
	paint(game);
	mlx_key_hook(game->ptr.win_ptr, deal_key, game);
	mlx_hook(game->ptr.win_ptr, KEYPRESS, 0, key_press, game);
	mlx_hook(game->ptr.win_ptr, MOUSEPRESS, 0, mouse_press, game);
	mlx_hook(game->ptr.win_ptr, MOUSERELEASE, 0, mouse_release, game);
	mlx_hook(game->ptr.win_ptr, MOUSEMOVE, 0, mouse_move, game);
	mlx_loop(game->ptr.mlx_ptr);
}
