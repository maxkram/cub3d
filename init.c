#include "./cub3d.h"

void	init_struct(t_game *game, char *arg, t_parse *parse)
{
	(void)arg;
	game->projection = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->height = 960;
	game->width = 1280;
	game->map = parse->map;
	game->key = 0;
	game->mlx_ptr = mlx_init(game->width, game->height, "Cub3d", false);
	init_player(game, parse);
	init_image(game);
	game->minimap = ft_calloc(sizeof(t_image), 1);
	game->max_view_distance = max_distance((ft_strlen(game->map[0]) - 1),
			tab_len(game->map));
	init_texture(game, parse);
	init_render(game);
	init_draw_ns(game);
	init_draw_oe(game);
	game->collor_cellar = parse->color_c;
	game->collor_floor = parse->color_f;
}