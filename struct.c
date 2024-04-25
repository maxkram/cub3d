#include "./cub3d.h"

void free_texture(char* texture) {
    if (texture != NULL)
        free(texture);
}

int free_struct(t_parse *parse)
{
    free_texture(parse->texture_ea);
    free_texture(parse->texture_no);
    free_texture(parse->texture_so);
    free_texture(parse->texture_we);
    free_texture(parse->value_rgb_c);
    free_texture(parse->value_rgb_f);
    free(parse);
    return 1;
}

void	init_render(t_game *game)
{
	game->render = ft_calloc(sizeof(t_render), 1);
	game->render->scale = 0.1;
	game->render->resolution_width = game->width;
	game->render->resolution_height = game->height;
	game->render->fov = M_PI / 6.0;
}

void	init_draw_ns(t_game *game)
{
	game->draw_ns = ft_calloc(sizeof(t_draw_ns), 1);
}

void	init_draw_oe(t_game *game)
{
	game->draw_oe = ft_calloc(sizeof(t_draw_oe), 1);
}

void	init_texture(t_game *game, t_parse *parse)
{
	int	i;

	i = -1;
	game->texture[0].texture = mlx_load_xpm42(parse->texture_no);
	game->texture[1].texture = mlx_load_xpm42(parse->texture_so);
	game->texture[2].texture = mlx_load_xpm42(parse->texture_ea);
	game->texture[3].texture = mlx_load_xpm42(parse->texture_we);
	while (++i < 4)
		if (!game->texture[i].texture)
			exit(1);
	game->texture[0].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[0].texture->texture);
	game->texture[1].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[1].texture->texture);
	game->texture[2].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[2].texture->texture);
	game->texture[3].img = mlx_texture_to_image(game->mlx_ptr,
			&game->texture[3].texture->texture);
	i = -1;
	while (++i < 4)
		if (!game->texture[i].img)
			exit(1);
}

float	max_distance(int map_width, int map_height)
{
	float	max_distance_x;
	float	max_distance_y;
	float	max_distance;

	max_distance_y = map_height * 16;
	max_distance_x = map_width * 16;
	max_distance = sqrt(max_distance_x * max_distance_x
			+ max_distance_y * max_distance_y);
	return (max_distance);
}