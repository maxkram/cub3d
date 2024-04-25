#include "./cub3d.h"

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
	while (game->map[i] && i != ft_strlen_tab(game->map))
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