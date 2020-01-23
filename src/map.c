/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:18:29 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 10:38:07 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			get_nbr_line(t_game *game)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
	if (!(fd = open(game->file, O_RDONLY)))
		print_error(game, ERROR_OPEN);
	else
	{
		while (get_next_line(fd, &line) == 1)
		{
			free(line);
			res++;
		}
	}
	if (close(fd) == -1)
		print_error(game, ERROR_CLOSE);
	return (res);
}

static void			get_nbr_char(t_game *game)
{
	int		i;

	i = 0;
	while (game->map.grid[i] != NULL)
		i++;
	game->map.max_x = i / game->map.max_y;
}

static char			*concat_str(char *str, char *add)
{
	char	*tmp;

	tmp = ft_strdup(str);
	str = ft_strjoin(tmp, add);
	free(tmp);
	tmp = ft_strdup(str);
	str = ft_strjoin(tmp, "  ");
	free(tmp);
	return (str);
}

static t_bool		read_file(t_game *game, char *file)
{
	int		fd;
	char	*line;
	char	*str;

	game->map.max_y = get_nbr_line(game);
	if (!(str = ft_strnew(0)))
		print_error(game, ERROR_MALLOC);
	if (!(fd = open(file, O_RDONLY)))
		print_error(game, ERROR_OPEN);
	else
	{
		while (get_next_line(fd, &line) == 1)
		{
			str = concat_str(str, line);
			free(line);
		}
		game->map.grid = ft_split_whitespace(str);
		get_nbr_char(game);
	}
	if (close(fd) == -1)
		print_error(game, ERROR_CLOSE);
	return (true);
}

t_bool				init_map(t_game *game, char *file)
{
	if (read_file(game, file) == false)
		return (false);
	return (true);
}
