/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:35:13 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 17:52:06 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_draw(int point[4], int delta[4],
		float vect1[3], float vect2[3])
{
	point[0] = vect1[0];
	point[2] = vect1[1];
	point[1] = vect2[0];
	point[3] = vect2[1];
	delta[0] = point[0] < point[1] ? 1 : -1;
	delta[1] = point[2] < point[3] ? 1 : -1;
	delta[2] = abs(point[1] - point[0]);
	delta[3] = abs(point[3] - point[2]);
}

static void		draw_line(t_ptr self, float vect1[3], float vect2[3], int color)
{
	int point[4];
	int delta[4];
	int err;
	int	e2;

	init_draw(point, delta, vect1, vect2);
	err = (delta[2] > delta[3] ? delta[2] : -delta[3]) / 2;
	while (1)
	{
		mlx_pixel_put(self.mlx_ptr, self.win_ptr, point[0] + self.x_center,
				-point[2] + self.y_center, color);
		if (point[0] == point[1] && point[2] == point[3])
			break ;
		e2 = err;
		if (e2 > -delta[2])
		{
			err -= delta[3];
			point[0] += delta[0];
		}
		if (e2 < delta[3])
		{
			err += delta[2];
			point[2] += delta[1];
		}
	}
}

static void		line_paint(t_game *game, t_line *line,
		t_line *world, float matrix[4][4])
{
	vector_transform(line->vect[0], matrix, world->vect[0]);
	vector_transform(line->vect[1], matrix, world->vect[1]);
	line_projection(game, line);
	line_clip(line, game->ptr);
	if (line->visible == 1)
		draw_line(game->ptr, line->vect[0], line->vect[1], game->color);
}

void			paint(t_game *game)
{
	t_line		*line;
	t_line		*world;
	float		matrix_transformation[4][4];

	line = game->lines;
	world = game->world;
	mlx_clear_window(game->ptr.mlx_ptr, game->ptr.win_ptr);
	camera_get_matrix(game->camera, matrix_transformation);
	while (line != NULL)
	{
		line_paint(game, line, world, matrix_transformation);
		line = line->next;
		world = world->next;
	}
	show_menu(game);
}
