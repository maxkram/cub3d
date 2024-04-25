#include "./cub3d.h"

void	messi_toty(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->render->resolution_width)
	{
		haaland_toty(game, x);
		game->render->distance_to_wall *= game->render->scale;
		game->render->distance_to_wall *= cos(game->player->pa
				- game->render->ray_angle);
		game->render->wall_height = (int)(game->render->resolution_height
				/ game->render->distance_to_wall) + 25;
		if (game->render->direction == 0 || game->render->direction == 1)
			draw_vertical_column_ns(game, x, (game->render->resolution_height
					- game->render->wall_height) / 2);
		else if (game->render->direction == 2 || game->render->direction == 3)
			draw_vertical_column_oe(game, x, (game->render->resolution_height
					- game->render->wall_height) / 2);
		else
			draw_vertical_column(game, x, (game->render->resolution_height
					- game->render->wall_height) / 2,
				color_pixel(150, 150, 150, 255));
		x++;
	}
}

void	render_3d(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx_ptr, game->third_d);
	game->third_d = mlx_new_image(game->mlx_ptr, game->width, game->height);
	mlx_image_to_window(game->mlx_ptr, game->third_d, 0, 0);
	print_floor_cellar(game);
	messi_toty(game);
	mlx_set_instance_depth(game->third_d->instances, 1);
}

void	print_textures_in_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_delete_image(game->mlx_ptr, game->minimap->img);
	game->minimap->img = mlx_new_image(game->mlx_ptr, 16, 16);
	ft_memset(game->minimap->img->pixels, 255, game->minimap->img->height
		* game->minimap->img->width * sizeof(int32_t));
	while (game->map[i] && i != tab_len(game->map))
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1' && game->map[i][j] != '0')
				mlx_image_to_window(game->mlx_ptr, game->minimap->img,
					j * 16, i * 16);
			j++;
		}
		i++;
	}
	mlx_set_instance_depth(game->minimap->img->instances, 1);
}