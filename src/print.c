/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:41:52 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 11:03:20 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_bool	print_usage(void)
{
	ft_putendl("usage: ./fdf [file_name]");
	return (false);
}

t_bool	print_error(t_game *game, int error)
{
	if (error == ERROR_MALLOC)
		ft_putendl("ERROR: Malloc returned NULL");
	if (error == ERROR_OPEN)
		ft_putendl("ERROR: Unable to open the file");
	if (error == ERROR_CLOSE)
		ft_putendl("ERROR: Unable to close the file");
	if (error == ERROR_MLX_INIT)
		ft_putendl("ERROR: mlx_init returned NULL");
	if (error == ERROR_NEW_WIN)
		ft_putendl("ERROR: mlx_new_window returned NULL");
	if (error == ERROR_INIT_GAME)
		ft_putendl("ERROR: Unable to init the game");
	free_all(game);
	exit(0);
	return (false);
}
