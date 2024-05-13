/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:19:34 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/12 22:00:19 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_bool	is_floor(t_file_data *data, int line, int col, int map_width)
{
	if (line <= 0 || line >= data->number_of_lines - 1
		|| col <= 0 || col >= map_width)
		return (FALSE);
	return (data->map_to_array[line - 1][col] <= 1 &&
			data->map_to_array[line + 1][col] <= 1 &&
			data->map_to_array[line][col - 1] <= 1 &&
			data->map_to_array[line][col + 1] <= 1);
}

t_value	validate_map(t_file_data *data, int map_width)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (line < data->number_of_lines)
	{
		while (col < map_width)
		{
			if (data->map_to_array[line][col] == FLOOR)
			{
				if (line == (data->number_of_lines - 1)
					|| !is_floor(data, line, col, map_width))
					data->return_value = OPEN_WALL;
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (data->return_value);
}

void	data_map_to_array(char *line_starts, t_file_data *data,
		int max_line_length, int current_line)
{
	int	i;

	i = 0;
	while (i < max_line_length && line_starts[i] != '\n'
		&& line_starts[i])
	{
		if (line_starts[i] == '1')
			data->map_to_array[current_line][i] = WALL;
		else if (line_starts[i] == 32)
			data->map_to_array[current_line][i] = EMPTY;
		else
			data->map_to_array[current_line][i] = FLOOR;
		i++;
	}
	while (i < max_line_length)
		data->map_to_array[current_line][i++] = EMPTY;
	data->map_to_array[current_line][max_line_length] = NEW_LINE;
}

t_value	create_map_for_data(t_file_data *data,
	int max_line_length, int current_line, char *line_starts)
{
	data->map_to_array[current_line] = (t_map_symbol *)ft_calloc(max_line_length
			+ 1, sizeof(int));
	if (!data->map_to_array[current_line])
	{
		data->return_value = MALLOC_FAIL;
		return (data->return_value);
	}
	data_map_to_array(line_starts, data, max_line_length, current_line);
	return (data->return_value);
}

t_value	move_string_to_map_array(t_file_data *data,
		char *map_as_string)
{
	char	*line_starts;
	int		current_line;

	current_line = 0;
	line_starts = map_as_string;
	data->max_width = max_length(map_as_string);
	data->map_to_array = (t_map_symbol **)
		ft_calloc(data->number_of_lines + 1, sizeof(int *));
	if (!data->map_to_array)
		return (data->return_value = MALLOC_FAIL);
	while (current_line < data->number_of_lines && *line_starts)
	{
		if (create_map_for_data(data, data->max_width,
				current_line, line_starts) != OK)
			return (data->return_value);
		line_starts = ft_strchr(line_starts, '\n');
		if (!line_starts)
			break ;
		line_starts++;
		current_line++;
	}
	data->map_to_array[data->number_of_lines] = NULL;
	validate_map(data, data->max_width);
	return (data->return_value);
}
