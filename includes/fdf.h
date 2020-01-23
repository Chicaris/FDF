/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:46:10 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/22 11:29:17 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx_macos/include/mlx.h"
# include <math.h>
# include <stdio.h>
# include <dirent.h>

# define ROUGE				0xFF0000
# define LIME				0x00FF00
# define MAGENTA			0xFF00FF
# define CYAN				0x00FFFF
# define YELLOW				0xFFFF00

# define ERROR_MALLOC		0
# define ERROR_OPEN			1
# define ERROR_CLOSE		2
# define ERROR_MLX_INIT		3
# define ERROR_NEW_WIN		4
# define ERROR_INIT_GAME	5

# define KEY_ESC			53
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_C				8
# define KEY_R				15
# define KEY_P				35
# define KEY_PLUS			24
# define KEY_MINUS			27
# define KEY_Q				12
# define KEY_E				14
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2

# define MOUSE_LEFT			1
# define MOUSE_RIGHT		2
# define MOUSE_UP			5
# define MOUSE_DOWN			4

# define KEYPRESS			2
# define MOUSEPRESS			4
# define MOUSERELEASE		5
# define MOUSEMOVE			6

# define CLIP_CENTER		0x0
# define CLIP_UP			0x1
# define CLIP_DOWN			0x2
# define CLIP_RIGHT			0x4
# define CLIP_LEFT			0x8

# define WIDTH				1600
# define LENGTH				1200

# define CAMERA_ORTHO		0
# define CAMERA_PROJ		1

/*
 	** Structures
*/

typedef enum		e_bool
{
	false, true
}					t_bool;

typedef	struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_mouse
{
	t_bool			status;
	int				button;
	int				current[2];
	int				last[2];
}					t_mouse;

typedef struct		s_ptr
{
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
	int				x_center;
	int				y_center;
}					t_ptr;

typedef struct		s_map
{
	int				max_x;
	int				max_y;
	char			**grid;
}					t_map;

typedef struct		s_line
{
	float			vect[2][3];
	int				visible;
	struct s_line	*next;
}					t_line;

typedef struct		s_camera
{
	int				projection;
	float			focal;
	float			origin[3];
	float			lookat[3];
	float			up[3];
}					t_camera;

typedef struct		s_game
{
	char			*file;
	t_ptr			ptr;
	t_map			map;
	t_line			*lines;
	t_line			*world;
	t_camera		camera;
	t_mouse			mouse;
	int				color;
}					t_game;

/*
	 ** Print.c
*/

t_bool				print_usage(void);

t_bool				print_error(t_game *game, int error);

/*
	 ** Camera.c
*/

void				camera_move(t_game *game, float vect[3]);

void				set_projection(t_game *game, int proj);

t_bool				init_camera(t_game *game);

/*
 	** Clip.c
*/

void				line_clip(t_line *line, t_ptr ptr);

/*
 	** Projection.c
*/

void				line_projection(t_game *game, t_line *line);

/*
 	** Move.c
*/

void				arrow_key(t_game *game, int key);

void				wsad_key(t_game *game, int key);

void				zoom_key(t_game *game, int key);

/*
 	** Key.c
*/

int					key_press(int key, void *param);

int					deal_key(int key, void *param);

/*
 	** Line_list.c
*/

t_bool				init_world(t_game *game);

t_bool				init_lines(t_game *game);

/*
 	** Map.c
*/

t_bool				init_map(t_game *game, char *file);

/*
 	** Matrix.c
*/

void				camera_get_matrix(t_camera self, float matrix[4][4]);

/*
 	** Menu.c
*/

void				show_menu(t_game *game);

/*
 	** Mouse.c
*/

int					mouse_press(int button, int x, int y, t_game *game);

int					mouse_release(int button, int x, int y, t_game *game);

int					mouse_move(int x, int y, t_game *game);

t_bool				init_mouse(t_game *game);

/*
 	** Paint.c
*/

void				paint(t_game *game);

/*
 	** Ptr.c
*/

t_bool				init_ptr(t_game *game);

void				mainloop(t_game *game);

/*
 	** Rotate_camera.c
*/

void				rotate_up(t_game *game, float theta);

void				rotate_rigth(t_game *game, float theta);

/*
 	** Free.c
*/

void				free_all(t_game *game);

#endif
