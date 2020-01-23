/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:15:53 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 17:52:48 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		get_up(float dest[3], float lookat[3],
		float origin[3], float up[3])
{
	float		up_axe[3];
	float		to_axe[3];
	float		rigth_axe[3];
	float		matrix_rot[4][4];
	float		matrix_trans[4][4];

	vector_diff(to_axe, origin, lookat);
	vector_normalize(to_axe);
	vector_cross(rigth_axe, to_axe, up);
	vector_normalize(rigth_axe);
	vector_cross(up_axe, rigth_axe, to_axe);
	vector_normalize(up_axe);
	vector_cpy(up, up_axe);
}

void			rotate_up(t_game *game, float theta)
{
	float	matrix[3][4][4];
	float	lookat[3];
	float	tmp[3];
	float	up[3];

	vector_cpy(tmp, game->camera.lookat);
	camera_get_matrix(game->camera, matrix[0]);
	vector_transform(lookat, matrix[0], tmp);
	vector_cpy(tmp, lookat);
	get_rotate_y(matrix[1], theta);
	vector_transform(lookat, matrix[1], tmp);
	vector_cpy(tmp, lookat);
	matrix_transpose(matrix[2], matrix[0]);
	vector_transform(lookat, matrix[2], tmp);
	vector_add(lookat, game->camera.origin);
	vector_cpy(game->camera.lookat, lookat);
	get_up(up, game->camera.lookat, game->camera.origin, game->camera.up);
	paint(game);
}

void			rotate_rigth(t_game *game, float theta)
{
	float	matrix[3][4][4];
	float	lookat[3];
	float	up[3];
	float	tmp[3];

	vector_cpy(tmp, game->camera.lookat);
	camera_get_matrix(game->camera, matrix[0]);
	vector_transform(lookat, matrix[0], tmp);
	vector_cpy(tmp, lookat);
	get_rotate_x(matrix[1], theta);
	vector_transform(lookat, matrix[1], tmp);
	vector_cpy(tmp, lookat);
	matrix_transpose(matrix[2], matrix[0]);
	vector_transform(lookat, matrix[2], tmp);
	vector_add(lookat, game->camera.origin);
	vector_cpy(game->camera.lookat, lookat);
	get_up(up, game->camera.lookat, game->camera.origin, game->camera.up);
	paint(game);
}
