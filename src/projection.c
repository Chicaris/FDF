/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:01:12 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 17:52:26 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	projection(t_line *line, int i)
{
	int scaling;

	scaling = (1.0 - line->vect[i][2]) /
		(line->vect[1 - i][2] - line->vect[i][2]);
	line->vect[i][0] += scaling *
		(line->vect[1 - i][0] - line->vect[i][0]);
	line->vect[i][1] += scaling *
		(line->vect[1 - i][1] - line->vect[i][1]);
	line->vect[i][2] = 1.0;
}

void		line_projection(t_game *game, t_line *line)
{
	float	scaling;
	int		i;
	float	vect[3];

	line->visible = 1;
	if (game->camera.projection == CAMERA_PROJ)
	{
		if ((line->vect[0][2] < 0.0) && (line->vect[1][2] < 0.0))
			line->visible = 0;
		i = 0;
		while (i < 2)
		{
			if (line->vect[i][2] <= 0.0)
				projection(line, i);
			scaling = game->camera.focal / line->vect[i][2];
			line->vect[i][0] = scaling * line->vect[i][0];
			line->vect[i][1] = scaling * line->vect[i][1];
			i++;
		}
	}
}
