/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:52:28 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 11:12:28 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_line	*create_line_j(t_game *game, int i, int j)
{
	t_line		*self;
	t_map		map;

	map = game->map;
	if (!(self = (t_line *)malloc(sizeof(t_line))))
		print_error(game, ERROR_MALLOC);
	get_vector(self->vect[0], i * 20, j * 20,
			ft_atoi(map.grid[j + i * map.max_x]) * 20);
	get_vector(self->vect[1], i * 20, (j + 1) * 20,
			ft_atoi(map.grid[(j + 1) + i * map.max_x]) * 20);
	self->next = NULL;
	return (self);
}

static t_line	*create_line_i(t_game *game, int i, int j)
{
	t_line		*self;
	t_map		map;

	map = game->map;
	if (!(self = (t_line *)malloc(sizeof(t_line))))
		print_error(game, ERROR_MALLOC);
	get_vector(self->vect[0], i * 20, j * 20,
			ft_atoi(map.grid[j + i * map.max_x]) * 20);
	get_vector(self->vect[1], (i + 1) * 20, j * 20,
			ft_atoi(map.grid[j + (i + 1) * map.max_x]) * 20);
	self->next = NULL;
	return (self);
}

static t_line	*lines(t_game *game, t_line *line, int i, int j)
{
	t_line	*tmp;

	tmp = line;
	if (j + 1 < game->map.max_x)
	{
		tmp->next = create_line_j(game, i, j);
		tmp = tmp->next;
	}
	if (i + 1 < game->map.max_y)
	{
		tmp->next = create_line_i(game, i, j);
		tmp = tmp->next;
	}
	return (tmp);
}

t_bool			init_world(t_game *game)
{
	int		i;
	int		j;
	t_line	*self;
	t_line	*tmp;

	tmp = create_line_j(game, 0, 0);
	self = tmp;
	i = 0;
	while (i < game->map.max_y)
	{
		j = 0;
		while (j < game->map.max_x)
		{
			tmp = lines(game, tmp, i, j);
			j++;
		}
		i++;
	}
	game->world = self->next;
	free(self);
	return (true);
}

t_bool			init_lines(t_game *game)
{
	int		i;
	int		j;
	t_line	*self;
	t_line	*tmp;

	tmp = create_line_j(game, 0, 0);
	self = tmp;
	i = 0;
	while (i < game->map.max_y)
	{
		j = 0;
		while (j < game->map.max_x)
		{
			tmp = lines(game, tmp, i, j);
			j++;
		}
		i++;
	}
	game->lines = self->next;
	free(self);
	return (true);
}
