/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:06:31 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 18:03:14 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		matrix_translation(float dst[4][4], float x, float y, float z)
{
	matrix_unit(dst);
	dst[0][3] = x;
	dst[1][3] = y;
	dst[2][3] = z;
}

static void		matrix_rotation(float matrix[4][4], float r_axe[3],
		float up_axe[3], float to_axe[3])
{
	int		i;
	int		j;

	matrix_unit(matrix);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i == 0)
				matrix[i][j] = r_axe[j];
			else if (i == 1)
				matrix[i][j] = up_axe[j];
			else
				matrix[i][j] = to_axe[j];
			j++;
		}
		i++;
	}
}

void			camera_get_matrix(t_camera self, float matrix[4][4])
{
	float		up_axe[3];
	float		to_axe[3];
	float		rigth_axe[3];
	float		matrix_rot[4][4];
	float		matrix_trans[4][4];

	vector_diff(to_axe, self.origin, self.lookat);
	vector_normalize(to_axe);
	vector_cross(rigth_axe, to_axe, self.up);
	vector_normalize(rigth_axe);
	vector_cross(up_axe, rigth_axe, to_axe);
	vector_normalize(up_axe);
	matrix_rotation(matrix_rot, rigth_axe, up_axe, to_axe);
	matrix_translation(matrix_trans, -self.origin[0], -self.origin[1],
			-self.origin[2]);
	matrix_multi(matrix, matrix_rot, matrix_trans);
}
