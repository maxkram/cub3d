#include "./cub3d.h"

void	pressed_key(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx_ptr);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_W))
		move(game, 1, cos(game->player->pa), sin(game->player->pa));
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_S))
		move(game, -1, cos(game->player->pa), sin(game->player->pa));
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_A))
		move(game, -1, cos(game->player->pa + (M_PI / 2)),
			sin(game->player->pa + (M_PI / 2)));
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_D))
		move(game, 1, cos(game->player->pa + (M_PI / 2)),
			sin(game->player->pa + (M_PI / 2)));
	camera(game);
}