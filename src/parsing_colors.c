/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:18:09 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/06 00:38:34 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	check_length_and_validate(t_file_data *data, char **grid)
{
	if (ft_arraylen(grid) != 3)
	{
		data->return_value = WRONG_COLORS;
		return ;
	}
	if (!ft_is_numerical(grid[0])
		|| !ft_is_numerical(grid[1]) || !ft_is_numerical(grid[2]))
		data->return_value = WRONG_COLORS;
}

bool	is_good_color(int color)
{
	return (color >= 0 && color < 256);
}

t_color	return_colors(t_file_data *data, char **rgb)
{
	t_color	colors;

	colors.red = 0;
	colors.green = 0;
	colors.blue = 0;
	check_length_and_validate(data, rgb);
	if (data->return_value != OK)
		return (colors);
	colors.red = ft_atoi(rgb[0]);
	colors.green = ft_atoi(rgb[1]);
	colors.blue = ft_atoi(rgb[2]);
	if (!is_good_color(colors.red) || !is_good_color(colors.green)
		|| !is_good_color(colors.blue))
		data->return_value = WRONG_COLORS;
	return (colors);
}

void	clean_grid(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (grid[i])
		free(grid[i++]);
	free(grid);
}

t_return_value	get_colors(t_file_data *data)
{
	char	**ceiling_rgbas;
	char	**floor_rgbas;

	ceiling_rgbas = ft_split(data->ceiling_color, ',');
	if (!ceiling_rgbas)
	{
		data->return_value = MALLOC_FAIL;
		return (data->return_value);
	}
	data->ceiling_rgb = return_colors(data, ceiling_rgbas);
	clean_grid(ceiling_rgbas);
	if (data->return_value != OK)
		return (data->return_value);
	floor_rgbas = ft_split(data->floor_color, ',');
	if (!floor_rgbas)
	{
		data->return_value = MALLOC_FAIL;
		return (data->return_value);
	}
	data->floor_rgb = return_colors(data, floor_rgbas);
	clean_grid(floor_rgbas);
	return (data->return_value);
}
