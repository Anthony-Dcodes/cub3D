#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 920
#define TEXT_WIDTH 64
#define TEXT_HEIGHT 64

#define NORTH 0 // dir_x = 0, dir_y = -1
#define SOUTH 1 // dir_x = 0, dir_y = 1
#define EAST 2 // dir_x = 1, dir_y = 0
#define WEST 3 // dir_x = -1, dir_y = 0
#define FLOOR 4
#define CEILING 5
#define UNKNOWN 6
#define EMPTY 7

#include <fcntl.h>
#include <stdlib.h>

typedef enum e_error
{
	ERR_OK,
	ERR_MALLOC,
	ERR_PARSER,
	ERR_RENDER,
	ERR_ARGS,
	ERR_MAP,
	ERR_RGB,
	ERR_TEXTURES
	// Bunch more Error codes needed for specific problems
}	t_error;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	pos_x; // PARSER x index + 0.5
	double	pos_y; // PARSER y index + 0.5
	double	dir_x; // PARSER
	double	dir_y; // PARSER
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
}	t_player;

typedef struct s_map
{
	int		map_width; // PARSER max width of the map
	int		map_height; // PARSER max height of the map
	char	**map; // PARSER
}	t_map;

typedef struct s_scene
{
	void		*mlx;
	void		*win;
	char		*tex_paths[4];
	int			win_w;
	int			win_h;
	t_img		frame;		// the frame buffer you draw into
	t_img		texture[4]; // NORTH, SOUTH, EAST, WEST
	t_map		map;
	t_player	player;
	int			floor_color;
	int			ceiling_color;
}	t_scene;
