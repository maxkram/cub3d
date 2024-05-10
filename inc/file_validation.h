#ifndef FILE_VALIDATION_H
# define FILE_VALIDATION_H

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}					t_color;

# define ELEMENTS_NEEDED 6
# define SPAWN_DIRECTION "NSEW"
# define SKIP_WHITE_SPACES 42
# define SKIP_CONSECUTIVE_NEW_LINES 24
# define N 1
# define S 2
# define W 3
# define E 4

typedef enum e_map_tile
{
	FLOOR,
	WALL,
	EMPTY,
	NEW_LINE
}					t_map_tile;

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef enum e_return_value
{
	OK,
	FAIL,
	MALLOC_FAIL,
	NEED_CUB,
	FILE_OPEN_FAIL,
	EMPTY_FILE,
	WRONG_MAP_CONTENT,
	SYMBOL_NOT_FOUND,
	SYMBOL_FOUND,
	MISSING_SYMBOL,
	DOUBLE,
	NO_SYMBOLS,
	ALL_SYMBOLS_FOUND,
	WRONG_PLAYER_DATA,
	WRONG_ARGUMENT,
	WRONG_DATA,
	MAP_EMPTY_LINE,
	OPEN_WALL,
	WRONG_COLORS,
}					t_return_value;

// Structure to hold information extracted from the scene description file
typedef struct s_file_data
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*floor_color;
	char			*ceiling_color;
	char			*file_content_as_string;
	t_map_tile		**map_as_array;
	char			player_spawn_direction[1];
	int				current_position;
	int				last_new_line_position;
	int				map_number_of_lines;
	int				direction_index;
	int				line_count;
	int				elements_found;
	double			player_x;
	double			player_y;
	int				file_descriptor;
	t_color			floor_rgb;
	t_color			ceiling_rgb;
	t_return_value	return_value;
	int				max_map_width;
}					t_file_data;

t_return_value		validate_cub_file(t_file_data *file_data,
						const char **path_to_file);
t_return_value		get_scene_elements_and_map(t_file_data *data);
t_return_value		check_scene_demands(t_file_data *data);
t_return_value		get_map_amount_of_lines(t_file_data *data,
						char *map_as_string);
char				*skip_leading_white_spaces(char *string_beginning);
t_return_value		move_string_to_map_array(t_file_data *data,
						char *map_as_string);
t_return_value		initialize_string_buffers(char **line_buffer,
						t_file_data *data);
int					get_max_line_length(char *map_as_string);
t_return_value		import_and_prepare_map(t_file_data *data,
						char *map_as_string);
t_return_value		check_map_does_not_contain_empty_lines(t_file_data *data,
						char *map_as_string);
#endif