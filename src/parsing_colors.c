/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:18:09 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/29 01:18:17 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static void	check_grid_len_and_validate(t_file_data *data, char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
		i++;
	if (i != 3)
	{
		data->return_value = INVALID_COLORS;
		return ;
	}
	if (!ft_is_numerical(grid[0])
		|| !ft_is_numerical(grid[1]) || !ft_is_numerical(grid[2]))
		data->return_value = INVALID_COLORS;
}

static t_bool	is_valid_color_value(int color)
{
	if (color >= 0 && color < 256)
		return (TRUE);
	return (FALSE);
}

static t_color	ret_colors(t_file_data *data, char **rgb)
{
	t_color	colors;
	int		valid_colors;

	colors.red = 0;
	colors.green = 0;
	colors.blue = 0;
	check_grid_len_and_validate(data, rgb);
	if (data->return_value != SUCCESS)
		return (colors);
	colors.red = ft_atoi(rgb[0]);
	colors.green = ft_atoi(rgb[1]);
	colors.blue = ft_atoi(rgb[2]);
	valid_colors = 0;
	valid_colors += is_valid_color_value(colors.red);
	valid_colors += is_valid_color_value(colors.green);
	valid_colors += is_valid_color_value(colors.blue);
	if (valid_colors < 3)
		data->return_value = INVALID_COLORS;
	return (colors);
}

static void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

t_return_value	get_rgb_colors(t_file_data *data)
{
	char	**ceiling_colors;
	char	**floor_colors;

	ceiling_colors = ft_split(data->ceiling_color, ',');
	if (!ceiling_colors)
	{
		data->return_value = MALLOC_FAILURE;
		return (data->return_value);
	}
	data->ceiling_rgb = ret_colors(data, ceiling_colors);
	free_grid(ceiling_colors);
	if (data->return_value != SUCCESS)
		return (data->return_value);
	floor_colors = ft_split(data->floor_color, ',');
	if (!floor_colors)
	{
		data->return_value = MALLOC_FAILURE;
		return (data->return_value);
	}
	data->floor_rgb = ret_colors(data, floor_colors);
	free_grid(floor_colors);
	return (data->return_value);
}
