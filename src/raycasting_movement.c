/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:21:19 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/13 01:10:04 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	rotate_direction_and_plane(t_data *d, int left_right)
{
	double	rotate_speed;
	double	prev_direct;
	double	prev_plane;

	rotate_speed = PLAYER_ROTATE_SPEED;
	if (left_right == 0)
		rotate_speed *= -1;
	prev_direct = d->player.dir.x;
	d->player.dir.x = d->player.dir.x * cos(rotate_speed)
		- d->player.dir.y * sin(rotate_speed);
	d->player.dir.y = prev_direct * sin(rotate_speed)
		+ d->player.dir.y * cos(rotate_speed);
	prev_plane = d->player.plane.x;
	d->player.plane.x = d->player.plane.x * cos(rotate_speed)
		- d->player.plane.y * sin(rotate_speed);
	d->player.plane.y = prev_plane * sin(rotate_speed)
		+ d->player.plane.y * cos(rotate_speed);
}

// void	parallel_move(t_data *d, int direction)
// {
// 	if (d->map.content[(int)d->player.pos.y]
// 		[(int)(d->player.pos.x
// 			+ direction * d->player.dir.x * (PLAYER_MOVE_SPEED * 1.001))] == 0)
// 		d->player.pos.x += direction * d->player.dir.x * PLAYER_MOVE_SPEED;
// 	if (d->map.content[(int)(d->player.pos.y
// 			+ direction * d->player.dir.y * (PLAYER_MOVE_SPEED * 1.001))]
// 			[(int)d->player.pos.x] == 0)
// 		d->player.pos.y += direction * d->player.dir.y * PLAYER_MOVE_SPEED;
// }

// void	perpendicular_move(t_data *d, int direction)
// {
// 	t_dvec	rot;

// 	rot.y = d->player.dir.x * -1;
// 	rot.x = d->player.dir.y;
// 	if (d->map.content[(int)d->player.pos.y]
// 		[(int)(d->player.pos.x
// 			+ direction * rot.x * (PLAYER_MOVE_SPEED * 1.001))] == 0)
// 		d->player.pos.x += direction * rot.x * PLAYER_MOVE_SPEED;
// 	if (d->map.content[(int)(d->player.pos.y
// 			+ direction * rot.y * (PLAYER_MOVE_SPEED * 1.001))]
// 			[(int)d->player.pos.x] == 0)
// 		d->player.pos.y += direction * rot.y * PLAYER_MOVE_SPEED;
// }

// void	update_player_location(t_data *d)
// {
// 	if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT))
// 		rotate_direction_and_plane(d, 0);
// 	if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT))
// 		rotate_direction_and_plane(d, 1);
// 	if (mlx_is_key_down(d->mlx, MLX_KEY_W))
// 		parallel_move(d, 1);
// 	if (mlx_is_key_down(d->mlx, MLX_KEY_S))
// 		parallel_move(d, -1);
// 	if (mlx_is_key_down(d->mlx, MLX_KEY_A))
// 		perpendicular_move(d, 1);
// 	if (mlx_is_key_down(d->mlx, MLX_KEY_D))
// 		perpendicular_move(d, -1);
// }

void	move_player(t_data *d, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = d->player.pos.x + dx;
	new_y = d->player.pos.y + dy;
	if (d->map.content[(int)new_y][(int)new_x] == 0)
	{
		d->player.pos.x = new_x;
		d->player.pos.y = new_y;
	}
}

void	update_player_location(t_data *d)
{
	if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT))
		rotate_direction_and_plane(d, 0);
	if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT))
		rotate_direction_and_plane(d, 1);
	if (mlx_is_key_down(d->mlx, MLX_KEY_W))
		move_player(d, d->player.dir.x * PLAYER_MOVE_SPEED,
			d->player.dir.y * PLAYER_MOVE_SPEED);
	if (mlx_is_key_down(d->mlx, MLX_KEY_S))
		move_player(d, -d->player.dir.x * PLAYER_MOVE_SPEED,
			-d->player.dir.y * PLAYER_MOVE_SPEED);
	if (mlx_is_key_down(d->mlx, MLX_KEY_A))
		move_player(d, -d->player.dir.y * PLAYER_MOVE_SPEED,
			d->player.dir.x * PLAYER_MOVE_SPEED);
	if (mlx_is_key_down(d->mlx, MLX_KEY_D))
		move_player(d, d->player.dir.y * PLAYER_MOVE_SPEED,
			-d->player.dir.x * PLAYER_MOVE_SPEED);
}
