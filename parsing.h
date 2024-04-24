#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_parse
{
	int		y_pl;
	int		x_pl;
	int		player_direction;
	bool	texture_check;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	char	*value_rgb_c;
	char	*value_rgb_f;
	int		color_c;
	int		color_f;
	char	**map;
}   t_parse;

#endif