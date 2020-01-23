/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:06:37 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 11:05:09 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		camera_move(t_game *game, float vect[3])
{
	int		i;

	i = 0;
	while (i < 3)
	{
		game->camera.origin[i] = game->camera.origin[i] + vect[i];
		game->camera.lookat[i] = game->camera.lookat[i] + vect[i];
		i++;
	}
}

void		set_projection(t_game *game, int proj)
{
	game->camera.projection = proj;
}

t_bool		init_camera(t_game *game)
{
	t_camera	self;

	self.projection = CAMERA_PROJ;
	self.focal = 1000.0;
	get_vector(self.origin, -100.0, -100.0, 100.0);
	get_vector(self.lookat, 0.0, 0.0, 50.0);
	get_vector(self.up, 0.0, 0.0, 50.0);
	game->camera = self;
	return (true);
}
