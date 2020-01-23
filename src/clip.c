/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:25:55 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 17:51:07 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		get_clip_code(float point[3], t_ptr ptr)
{
	int code;

	code = 0;
	if (point[0] > ptr.x_max)
		code |= CLIP_RIGHT;
	if (point[0] < ptr.x_min)
		code |= CLIP_LEFT;
	if (point[1] > ptr.y_max)
		code |= CLIP_UP;
	if (point[1] < ptr.y_min)
		code |= CLIP_DOWN;
	return (code);
}

static void		clip_condition(t_ptr ptr, float *pin, float *pout,
		int condition)
{
	if (condition == 1)
	{
		pout[0] = pin[0] + (pout[0] - pin[0]) / (pout[1] - pin[1])
			* ((float)ptr.y_max - pin[1]);
		pout[1] = ptr.y_max;
	}
	else if (condition == 2)
	{
		pout[0] = pin[0] + (pout[0] - pin[0]) / (pout[1] - pin[1])
			* ((float)ptr.y_min - pin[1]);
		pout[1] = ptr.y_min;
	}
	else if (condition == 3)
	{
		pout[1] = pin[1] + (pout[1] - pin[1]) / (pout[0] - pin[0])
			* ((float)ptr.x_max - pin[0]);
		pout[0] = ptr.x_max;
	}
	else if (condition == 4)
	{
		pout[1] = pin[1] + (pout[1] - pin[1]) / (pout[0] - pin[0])
			* ((float)ptr.x_min - pin[0]);
		pout[0] = ptr.x_min;
	}
}

static void		clip(t_line *line, t_ptr ptr, int clip_code[2])
{
	int		out_idx;
	float	*pin;
	float	*pout;

	out_idx = (clip_code[0] != CLIP_CENTER) ? 0 : 1;
	pout = line->vect[out_idx];
	pin = line->vect[1 - out_idx];
	if ((clip_code[out_idx] & CLIP_UP) != 0)
		clip_condition(ptr, pin, pout, 1);
	else if ((clip_code[out_idx] & CLIP_DOWN) != 0)
		clip_condition(ptr, pin, pout, 2);
	else if ((clip_code[out_idx] & CLIP_RIGHT) != 0)
		clip_condition(ptr, pin, pout, 3);
	else if ((clip_code[out_idx] & CLIP_LEFT) != 0)
		clip_condition(ptr, pin, pout, 4);
}

void			line_clip(t_line *line, t_ptr ptr)
{
	int		clip_code[2];
	int		i;

	while (1)
	{
		i = 0;
		while (i < 2)
		{
			clip_code[i] = get_clip_code(line->vect[i], ptr);
			i++;
		}
		if ((clip_code[0] & clip_code[1]) != CLIP_CENTER)
		{
			line->visible = 0;
			break ;
		}
		clip(line, ptr, clip_code);
		if ((clip_code[0] | clip_code[1]) == CLIP_CENTER)
			break ;
		else
			break ;
	}
}
