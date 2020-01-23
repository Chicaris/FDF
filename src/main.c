/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:38:38 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 11:06:24 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_bool	is_file(char *file)
{
	DIR		*directory;

	directory = opendir(file);
	if (directory != NULL)
	{
		closedir(directory);
		return (false);
	}
	return (true);
}

static t_bool	init_game(t_game *game, char *file)
{
	game->file = ft_strdup(file);
	game->color = ROUGE;
	if (!(init_ptr(game)))
		return (false);
	if (!(init_map(game, file)))
		return (false);
	if (!(init_lines(game)))
		return (false);
	if (!(init_world(game)))
		return (false);
	if (!(init_camera(game)))
		return (false);
	if (!(init_mouse(game)))
		return (false);
	return (true);
}

int				main(int argc, char *argv[])
{
	t_game *game;

	game = NULL;
	if (argc != 2 || is_file(argv[1]) == false)
		return (print_usage());
	else
	{
		if (!(game = (t_game *)malloc(sizeof(t_game))))
			return (false);
		if (!(init_game(game, argv[1])))
			print_error(game, ERROR_INIT_GAME);
		mainloop(game);
	}
	return (true);
}
