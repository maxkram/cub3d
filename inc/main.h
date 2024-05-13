/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 02:53:52 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/12 23:42:11 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define WINDOW_WIDTH 720
# define WINDOW_HEIGHT 480
# define PLAYER_FOV 65
# define PLAYER_MOVE_SPEED 0.025
# define PLAYER_ROTATE_SPEED 0.03
# define TEXTURE_SIZE_MIN 1
# define TEXTURE_SIZE_MAX 64
# define COLOR_BLACK 0x000000FF
# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_GREEN 0x90FD90FF
# define COLOR_RED 0xCC3636FF
# define COLOR_PINK 0xE97FC2FF
# define COLOR_BLUE 0x35CFE4FF
# define COLOR_GRAY 0x5F574FFF

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "check_file.h"

typedef enum e_program_phase
{
	PHASE_PARSING,
	PHASE_RENDERING
}					t_program_phase;

typedef struct s_dvec
{
	double			x;
	double			y;
}					t_dvec;

typedef struct s_player
{
	t_dvec			pos;
	t_dvec			dir;
	t_dvec			plane;
}					t_player;

typedef struct s_color_data
{
	int				floor;
	int				ceiling;
}					t_color_data;

typedef struct s_texture_data
{
	mlx_texture_t	*north;
	mlx_texture_t	*east;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
}					t_texture_data;

typedef struct s_map
{
	int				width;
	int				height;
	int				**content;
}					t_map;

typedef struct s_data
{
	t_player		player;
	t_color_data	color;
	t_texture_data	texture;
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*img;
}					t_data;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_line
{
	t_point			start;
	t_point			end;
	unsigned int	color;
}					t_line;

typedef struct s_ray
{
	t_dvec			dir;
	double			cam_x;
	t_point			map;
	t_dvec			side_dist;
	t_dvec			delta_dist;
	double			normal_wall_distance;
	t_point			step;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_hit_dec;
	mlx_texture_t	*texture;
	t_point			tex_pos;
}					t_ray;

// Function declarations
void				create_struct(t_file_data *structure_pointer);
void				print_parse_error(t_value error);
t_value				check_file_type(t_file_data *data,
						const char **path_to_file);
t_value				map_to_string(t_file_data *data,
						const char **path);
void				clean_up_parsing(t_file_data *data);
t_value				check_scene_demands(t_file_data *data);
void				render(t_data *d);
void				hook_loop(void *data_param);
void				hook_close(void *data_param);
void				hook_key(mlx_key_data_t keydata, void *data_param);
void				clean_and_exit(t_data *d, int exit_status);
double				deg_to_rad(double degrees);
unsigned int		get_texture_pixel(mlx_texture_t *texture, unsigned int x,
						unsigned int y);
void				init_player_dir_plane(t_data *d, int player_angle_deg,
						int fov);
unsigned int		convert_abgr_to_rgba(unsigned int agbr);
void				put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
						uint32_t color);
void				render_ceiling_floor(t_data *d);
void				update_player_location(t_data *d);
void				move_player_direction(t_file_data *file_data,
						t_data *render_data);
void				cast_rays(t_data *d);
void				draw_texture(t_data *d, t_ray *ray, int x);
void				start_ray_base(t_data *d, t_ray *ray, int x);
void				init_ray_delta(t_ray *ray);
void				init_ray_side_distance(t_data *d, t_ray *ray);
t_value				get_colors(t_file_data *data);
t_bool				ft_is_numerical(char *str);
void				exit_from_parse(t_file_data *file_data, int return_value);
void				exit_mlx_parse(t_file_data *file_data,
						int return_value, mlx_t *mlx);
void				clean_struct_4_map(t_file_data *data);
void				move_colors(t_file_data *file_data, t_data *render_data);
void				exit_bad_argc(void);
void				check_all_textures(t_data *render_data);
t_value				validate_color_strings(t_file_data *data);

#endif
