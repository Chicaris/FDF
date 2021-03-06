/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_unit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:09:57 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 13:09:58 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	matrix_unit(float matrix[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (j == i)
				matrix[i][j] = 1.0;
			else
				matrix[i][j] = 0.0;
			j++;
		}
		i++;
	}
}
