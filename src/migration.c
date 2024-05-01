/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   migration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:10:30 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/01 00:58:02 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	migrate_player_direction(t_file_data *file_data, t_data *render_data)
{
	int		degrees;
	char	direction;

	degrees = 60;
	direction = file_data->player_spawn_direction[0];
	if (direction == 'E')
		degrees = 90;
	if (direction == 'S')
		degrees = 180;
	if (direction == 'W')
		degrees = 270;
	init_player_dir_plane(render_data, degrees, PLAYER_FOV);
}

static unsigned int	migrate_colors_to_rgba(
	unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void	exit_parsing(t_file_data *file_data, int return_value)
{
	print_parsing_error_message(return_value);
	clean_up_parsing(file_data);
	exit(1);
}

void	exit_mlx_parsing(t_file_data *file_data, int return_value, mlx_t *mlx)
{
	mlx_terminate(mlx);
	exit_parsing(file_data, return_value);
}

void	migrate_colors(t_file_data *file_data, t_data *render_data)
{
	render_data->color.floor = migrate_colors_to_rgba(
			(unsigned int)file_data->floor_rgb.red,
			(unsigned int)file_data->floor_rgb.green,
			(unsigned int)file_data->floor_rgb.blue, 255);
	render_data->color.ceiling = migrate_colors_to_rgba(
			(unsigned int)file_data->ceiling_rgb.red,
			(unsigned int)file_data->ceiling_rgb.green,
			(unsigned int)file_data->ceiling_rgb.blue, 255);
}
