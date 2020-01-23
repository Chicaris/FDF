/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:14:27 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 17:52:02 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		get_axe(t_game *game, float up_axe[3], float to_axe[3],
		float rigth_axe[3])
{
	vector_diff(to_axe, game->camera.origin, game->camera.lookat);
	vector_normalize(to_axe);
	vector_cross(rigth_axe, to_axe, game->camera.up);
	vector_normalize(rigth_axe);
	vector_cross(up_axe, rigth_axe, to_axe);
	vector_normalize(up_axe);
}

void			arrow_key(t_game *game, int key)
{
	if (key == KEY_LEFT)
		rotate_up(game, -M_PI / 18);
	if (key == KEY_RIGHT)
		rotate_up(game, M_PI / 18);
	if (key == KEY_UP)
		rotate_rigth(game, -M_PI / 18);
	if (key == KEY_DOWN)
		rotate_rigth(game, M_PI / 18);
}

void			zoom_key(t_game *game, int key)
{
	float		to_axe[3];

	vector_diff(to_axe, game->camera.origin, game->camera.lookat);
	vector_normalize(to_axe);
	if (key == KEY_PLUS)
	{
		vector_scale(to_axe, 20.0);
		vector_add(game->camera.origin, to_axe);
		vector_add(game->camera.lookat, to_axe);
	}
	if (key == KEY_MINUS)
	{
		vector_scale(to_axe, -20.0);
		vector_add(game->camera.origin, to_axe);
		vector_add(game->camera.lookat, to_axe);
	}
	paint(game);
}

void			wsad_key(t_game *game, int key)
{
	float		axe[3][3];

	get_axe(game, axe[2], axe[0], axe[1]);
	if (key == KEY_W)
	{
		vector_scale(axe[2], 10.0);
		camera_move(game, axe[2]);
	}
	if (key == KEY_S)
	{
		vector_scale(axe[2], -10.0);
		camera_move(game, axe[2]);
	}
	if (key == KEY_A)
	{
		vector_scale(axe[1], -10.0);
		camera_move(game, axe[1]);
	}
	if (key == KEY_D)
	{
		vector_scale(axe[1], 10.0);
		camera_move(game, axe[1]);
	}
	paint(game);
}
