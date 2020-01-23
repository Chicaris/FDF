/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:40:55 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 11:12:39 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		free_lines(t_line *line)
{
	t_line	*tmp;

	while (line != NULL)
	{
		tmp = line;
		line = line->next;
		free(tmp);
	}
}

void			free_all(t_game *game)
{
	if (game->file != NULL)
		free(game->file);
	if (game->map.grid != NULL)
		free(game->map.grid);
	if (game->lines != NULL)
		free_lines(game->lines);
	if (game->world != NULL)
		free_lines(game->world);
	free(game);
}
