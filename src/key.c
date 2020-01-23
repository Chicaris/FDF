/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:07:09 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 17:51:15 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	proj_key(t_game *game)
{
	if (game->camera.projection == CAMERA_ORTHO)
		set_projection(game, CAMERA_PROJ);
	else
		set_projection(game, CAMERA_ORTHO);
	paint(game);
}

static void	set_color(t_game *game)
{
	if (game->color == ROUGE)
		game->color = LIME;
	else if (game->color == LIME)
		game->color = MAGENTA;
	else if (game->color == MAGENTA)
		game->color = CYAN;
	else if (game->color == CYAN)
		game->color = YELLOW;
	else if (game->color == YELLOW)
		game->color = ROUGE;
	else
		game->color = ROUGE;
	paint(game);
}

int			key_press(int key, void *param)
{
	t_game		*self;

	self = (t_game *)param;
	if (self->camera.projection == CAMERA_PROJ)
	{
		arrow_key(self, key);
		zoom_key(self, key);
	}
	wsad_key(self, key);
	return (0);
}

int			deal_key(int key, void *param)
{
	t_game		*self;

	self = (t_game *)param;
	if (key == KEY_ESC)
	{
		free(self);
		exit(0);
	}
	if (key == KEY_P)
		proj_key(self);
	if (key == KEY_C)
		set_color(self);
	return (0);
}
