#include "./cub3d.h"

void	move(t_game *game, int value, float angle_x, float angle_y)
{
	float	new_px;
	float	new_py;

	new_py = game->player->py + value * angle_y;
	new_px = game->player->px + value * angle_x;
	if (is_a_wall(game->map, new_px, new_py))
		return ;
	if (!player_collision(game->map, new_px, game->player->py))
	{
		game->image_player->img->instances->x = new_px;
		game->player->px = new_px;
	}
	if (!player_collision(game->map, game->player->px, new_py))
	{
		game->image_player->img->instances->y = new_py;
		game->player->py = new_py;
	}
}

void	camera(t_game *game)
{
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_LEFT))
	{
		game->player->pa -= 0.07;
		if (game->player->pa < 0)
			game->player->pa += 2 * M_PI;
	}
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_RIGHT))
	{
		game->player->pa += 0.07;
		if (game->player->pa > 2 * M_PI)
			game->player->pa -= 2 * M_PI;
	}
}

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