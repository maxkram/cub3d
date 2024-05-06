/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   migration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:10:30 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/06 00:02:48 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	move_player_direction(t_file_data *file_data, t_data *render_data)
{
	int		degrees;
	char	direction;

	degrees = 0;
	direction = file_data->player_spawn_direction[0];
	if (direction == 'E')
		degrees = 90;
	if (direction == 'S')
		degrees = 180;
	if (direction == 'W')
		degrees = 270;
	init_player_dir_plane(render_data, degrees, PLAYER_FOV);
}

uint32_t	move_colors_to_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void	exit_from_parse(t_file_data *file_data, int return_value)
{
	print_parse_error(return_value);
	clean_up_parsing(file_data);
	exit(1);
}

void	exit_mlx_parse(t_file_data *file_data, int return_value, mlx_t *mlx)
{
	mlx_terminate(mlx);
	exit_from_parse(file_data, return_value);
}

void	move_colors(t_file_data *file_data, t_data *render_data)
{
	render_data->color.floor = move_colors_to_rgba(
			(uint32_t)file_data->floor_rgb.red,
			(uint32_t)file_data->floor_rgb.green,
			(uint32_t)file_data->floor_rgb.blue, 255);
	render_data->color.ceiling = move_colors_to_rgba(
			(uint32_t)file_data->ceiling_rgb.red,
			(uint32_t)file_data->ceiling_rgb.green,
			(uint32_t)file_data->ceiling_rgb.blue, 255);
}
