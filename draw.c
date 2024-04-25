#include "./cub3d.h"

void	draw_vertical_column_oe_2(t_game *game, int i, int x, int y)
{
	game->draw_oe->pixel_y = y + i;
	game->draw_oe->texture_y = i * game->draw_oe->texture_height
		/ game->render->wall_height;
	game->draw_oe->texture_pixel_index = (game->draw_oe->texture_y
			* game->draw_oe->texture_width + game->draw_oe->texture_x) * 4;
	game->draw_oe->r = game->draw_oe->texture_pixels
	[game->draw_oe->texture_pixel_index + 0];
	game->draw_oe->g = game->draw_oe->texture_pixels
	[game->draw_oe->texture_pixel_index + 1];
	game->draw_oe->b = game->draw_oe->texture_pixels
	[game->draw_oe->texture_pixel_index + 2];
	game->draw_oe->a = game->draw_oe->texture_pixels
	[game->draw_oe->texture_pixel_index + 3];
	game->draw_oe->color = color_pixel(game->draw_oe->r, game->draw_oe->g,
			game->draw_oe->b, game->draw_oe->a);
	if (game->draw_oe->pixel_y >= 0 && game->draw_oe->pixel_y < game->height)
		mlx_put_pixel(game->third_d, x, game->draw_oe->pixel_y,
			game->draw_oe->color);
}

void	draw_vertical_column_oe(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	game->draw_oe->texture_width
		= game->texture[game->render->direction].img->width;
	game->draw_oe->texture_height
		= game->texture[game->render->direction].img->height;
	game->draw_oe->texture_pixels
		= game->texture[game->render->direction].img->pixels;
	if (game->render->ray_y == floor(game->render->ray_y))
		game->draw_oe->wall_x = game->render->ray_x
			- floor(game->render->ray_x);
	else
		game->draw_oe->wall_x = game->render->ray_y
			- floor(game->render->ray_y);
	game->draw_oe->texture_x = game->draw_oe->wall_x
		* game->draw_oe->texture_width;
	if (game->render->ray_y > game->render->ray_x)
		game->draw_oe->texture_x = game->draw_oe->texture_width
			- game->draw_oe->texture_x - 1;
	while (i < game->render->wall_height)
	{
		draw_vertical_column_oe_2(game, i, x, y);
		i++;
	}
}

void	draw_vertical_column(t_game *game, int x, int y, int color)
{
	int	i;
	int	pixel_y;

	i = 0;
	while (i < game->render->wall_height)
	{
		pixel_y = y + i;
		if (pixel_y >= 0 && pixel_y < game->height)
			mlx_put_pixel(game->third_d, x, pixel_y, color);
		i++;
	}
}

void	draw_vertical_column_ns_2(t_game *game, int i, int x)
{
	game->draw_ns->texture_y = ((i * game->draw_ns->texture_height)
			/ game->render->wall_height) % game->draw_ns->texture_height;
	game->draw_ns->texture_pixel_x = game->draw_ns->texture_x
		% game->draw_ns->texture_width;
	if (game->draw_ns->texture_pixel_x < 0)
		game->draw_ns->texture_pixel_x += game->draw_ns->texture_width;
	game->draw_ns->texture_pixel_index = (game->draw_ns->texture_y
			* game->draw_ns->texture_width
			+ game->draw_ns->texture_pixel_x) * 4;
	game->draw_ns->r = game->draw_ns->texture_pixels
	[game->draw_ns->texture_pixel_index + 0];
	game->draw_ns->g = game->draw_ns->texture_pixels
	[game->draw_ns->texture_pixel_index + 1];
	game->draw_ns->b = game->draw_ns->texture_pixels
	[game->draw_ns->texture_pixel_index + 2];
	game->draw_ns->a = game->draw_ns->texture_pixels
	[game->draw_ns->texture_pixel_index + 3];
	game->draw_ns->color = color_pixel(game->draw_ns->r, game->draw_ns->g,
			game->draw_ns->b, game->draw_ns->a);
	mlx_put_pixel(game->third_d, x, game->draw_ns->pixel_y,
		game->draw_ns->color);
}

void	draw_vertical_column_ns(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	game->draw_ns->texture_width
		= game->texture[game->render->direction].img->width;
	game->draw_ns->texture_height
		= game->texture[game->render->direction].img->height;
	game->draw_ns->texture_pixels
		= game->texture[game->render->direction].img->pixels;
	if (game->render->ray_y == floor(game->render->ray_y))
		game->draw_ns->wall_x = game->render->ray_x
			- floor(game->render->ray_x);
	else
		game->draw_ns->wall_x = game->render->ray_x
			- floor(game->render->ray_x) - 1;
	game->draw_ns->texture_x = game->draw_ns->wall_x
		* game->draw_ns->texture_width;
	while (i < game->render->wall_height)
	{
		game->draw_ns->pixel_y = y + i;
		if (game->draw_ns->pixel_y >= 0
			&& game->draw_ns->pixel_y < game->height)
			draw_vertical_column_ns_2(game, i, x);
		i++;
	}
}
