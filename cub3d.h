#ifndef CUB3D_H
#define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "parsing.h"
# include "./MLX42.h"

typedef struct draw_oe
{
	uint8_t		*texture_pixels;
	int			texture_width;
	int			texture_height;
	int			texture_x;
	int			texture_y;
	int			texture_pixel_index;
	int			pixel_y;
	uint8_t		r;
	uint8_t		b;
	uint8_t		g;
	uint8_t		a;
	uint32_t	color;
	float		wall_x;
}	t_draw_oe;

typedef struct draw_ns
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	uint8_t		*texture_pixels;
	uint32_t	color;
	int			texture_width;
	int			texture_height;
	int			texture_x;
	int			texture_y;
	int			texture_pixel_x;
	int			texture_pixel_index;
	int			pixel_y;
	float		wall_x;
}	t_draw_ns;
typedef struct render
{
	float	ray_angle;
	float	scale;
	float	ray_x;
	float	ray_y;
	float	fov;
	double	cos_ray;
	double	sin_ray;
	float	distance_to_wall;
	bool	hit_wall;
	int		direction;
	int		resolution_width;
	int		resolution_height;
	int		wall_height;
}	t_render;
typedef struct image
{
	xpm_t		*texture;
	mlx_image_t	*img;
	mlx_image_t	*img_2;
	char		*path;
}	t_image;

typedef struct player
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
}	t_player;
typedef struct game
{
    void		*mlx_ptr;
	char		**map;
	int			key;
	int			width;
	int			height;
	int			collor_cellar;
	int			collor_floor;
	float		max_view_distance;
	t_image		texture[4];
	mlx_image_t	*projection;
	mlx_image_t	*third_d;
	t_image		*image_player;
	t_image		*minimap;
	t_player	*player;
	t_render	*render;
	t_draw_ns	*draw_ns;
	t_draw_oe	*draw_oe;
}   t_game;

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	init_struct(t_game *game, char *arg, t_parse *parse);
void	print_textures_in_minimap(t_game *game);
void	pressed_key(void *param);
void	render_3d(void *param);
bool	start_parsing(int ac, char **av, t_parse *parse);
int		free_struct(t_parse *parse);

#endif