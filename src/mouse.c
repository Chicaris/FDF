/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:51:46 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 17:51:58 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		move_camera(t_game *game, int button)
{
	float		up_axe[3];
	float		to_axe[3];
	float		rigth_axe[3];
	float		rayon;

	vector_diff(to_axe, game->camera.origin, game->camera.lookat);
	vector_normalize(to_axe);
	vector_cross(rigth_axe, to_axe, game->camera.up);
	vector_normalize(rigth_axe);
	vector_cross(up_axe, rigth_axe, to_axe);
	vector_normalize(up_axe);
	if (button == MOUSE_UP)
	{
		vector_scale(to_axe, 20.0);
		vector_add(game->camera.origin, to_axe);
		vector_add(game->camera.lookat, to_axe);
	}
	if (button == MOUSE_DOWN)
	{
		vector_scale(to_axe, -20.0);
		vector_add(game->camera.origin, to_axe);
		vector_add(game->camera.lookat, to_axe);
	}
	paint(game);
}

int				mouse_press(int button, int x, int y, t_game *game)
{
	game->mouse.status = true;
	if (button == 1)
	{
		game->mouse.button = 1;
		game->mouse.last[0] = x;
		game->mouse.last[1] = y;
	}
	if (button == 5)
	{
		game->mouse.button = 5;
		move_camera(game, button);
	}
	if (button == 4)
	{
		game->mouse.button = 4;
		move_camera(game, button);
	}
	return (0);
}

int				mouse_release(int button, int x, int y, t_game *game)
{
	if (game->mouse.button == 1)
	{
		game->mouse.status = false;
		game->mouse.current[0] = x;
		game->mouse.current[1] = y;
	}
	game->mouse.button = 0;
	return (0);
}

int				mouse_move(int x, int y, t_game *game)
{
	int		delta_x;
	int		delta_y;
	float	theta;
	float	sigma;

	if (game->mouse.status == true)
	{
		if (game->mouse.button == 1)
		{
			delta_x = game->mouse.last[0] - x;
			delta_y = game->mouse.last[1] - y;
			theta = M_PI * (delta_x / 175) / 18;
			sigma = M_PI * (delta_y / 175) / 18;
			rotate_up(game, theta);
			rotate_rigth(game, sigma);
		}
	}
	return (0);
}

t_bool			init_mouse(t_game *game)
{
	t_mouse		self;

	self.status = false;
	self.button = 0;
	self.current[0] = 0;
	self.current[1] = 0;
	self.last[0] = 0;
	self.last[1] = 0;
	game->mouse = self;
	return (true);
}
