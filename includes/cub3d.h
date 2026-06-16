#pragma once

#define screenWidth 640
#define screenHeight 480

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
}	t_error;


typedef struct s_map
{
	int		map_widht;
	int		map_height;
	char	**map;
}	t_map;

// Window context + image
typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	void		*img;
	char		*i_addr;
	int			i_bits_per_pixel;
	int			i_line_length;
	int			i_endian;
}	t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
	t_mlx	mlx_struct;
	t_map	world_map;
} t_player;
