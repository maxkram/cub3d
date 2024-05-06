/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:13:53 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/06 01:37:48 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_return_value	check_cub_file(
		t_file_data *data, const char **path_to_file)
{
	char	*temp;

	if (check_file_type(data, path_to_file) == OK)
	{
		if (map_to_string(data, path_to_file) == FILE_OPEN_FAIL)
			return (data->return_value);
		temp = ft_strtrim(data->file_content_as_string, " \t\v\f\r\n");
		free(data->file_content_as_string);
		data->file_content_as_string = ft_strdup(temp);
		free(temp);
	}
	if (data->return_value == OK)
		check_scene_demands(data);
	return (data->return_value);
}

void	parse(t_file_data *file_data, char **argv)
{
	initialize_struct(file_data);
	file_data->return_value = OK;
	check_cub_file(file_data, (const char **)argv);
	if (file_data->return_value != OK)
		exit_from_parse(file_data, file_data->return_value);
}

t_return_value	move_data_to_render(
		t_file_data *file_data, t_data *render_data)
{
	render_data->texture.north = mlx_load_png(file_data->north_texture);
	if (!render_data->texture.north)
		return (FAIL);
	render_data->texture.east = mlx_load_png(file_data->east_texture);
	if (!render_data->texture.east)
		return (FAIL);
	render_data->texture.south = mlx_load_png(file_data->south_texture);
	if (!render_data->texture.south)
		return (FAIL);
	render_data->texture.west = mlx_load_png(file_data->west_texture);
	if (!render_data->texture.west)
		return (FAIL);
	render_data->map.height = file_data->map_number_of_lines;
	render_data->map.width = file_data->max_map_width;
	render_data->map.content = (int **)file_data->map_as_array;
	render_data->player.pos.x = file_data->player_x + 0.5;
	render_data->player.pos.y = file_data->player_y + 0.5;
	move_player_direction(file_data, render_data);
	move_colors(file_data, render_data);
	return (OK);
}

void	init(t_file_data *file_data, t_data *render_data)
{
	render_data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!render_data->mlx)
		exit_from_parse(file_data, MALLOC_FAIL);
	render_data->img = mlx_new_image(render_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if ((!render_data->img
			|| (move_data_to_render(file_data, render_data) == FAIL))
		|| (mlx_image_to_window(render_data->mlx, render_data->img, 0, 0) < 0))
		exit_mlx_parse(file_data, FAIL, render_data->mlx);
	clean_struct_4_map(file_data);
	check_all_textures(render_data);
	mlx_loop_hook(render_data->mlx, hook_loop, render_data);
	mlx_close_hook(render_data->mlx, hook_close, render_data);
	mlx_key_hook(render_data->mlx, hook_key, render_data);
}

int	main(int argc, char **argv)
{
	t_data			render_data;
	t_file_data		file_data;

	if (argc != 2)
		exit_bad_argc();
	parse(&file_data, argv);
	init(&file_data, &render_data);
	mlx_loop(render_data.mlx);
	clean_and_exit(&render_data, 0);
	return (0);
}
