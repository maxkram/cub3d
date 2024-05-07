/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_and_player_import.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:19:07 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/07 05:37:34 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	fill_player_data(t_file_data *data, char *input_string,
		char player_spawn_direction)
{
	data->player_x = data->current_position - data->last_new_line_position - 1;
	data->player_y = data->line_count;
	*data->player_spawn_direction = player_spawn_direction;
	input_string[data->current_position] = '0';
}

t_return_value	get_player_position(t_file_data *data,
	char *input_string, const char *spawn_direction_delimiter)
{
	while (input_string[data->current_position])
	{
		if (input_string[data->current_position] == '\n')
		{
			data->line_count++;
			data->last_new_line_position = data->current_position;
		}
		data->direction_index = 0;
		while (spawn_direction_delimiter[data->direction_index])
		{
			if (input_string[data->current_position]
				== spawn_direction_delimiter[data->direction_index])
			{
				fill_player_data(data, input_string,
					spawn_direction_delimiter[data->direction_index]);
				return (data->return_value);
			}
			data->direction_index++;
		}
		data->current_position++;
	}
	data->return_value = PLAYER_DATA_INCORRECT_OR_MISSING;
	return (data->return_value);
}

t_return_value	check_symbols_in_map(t_file_data *data,
										char *map_as_string)
{
	while (*map_as_string)
	{
		if (*map_as_string != ' ' && *map_as_string != '0'
			&& *map_as_string != '1' && *map_as_string != '\n')
		{
			data->return_value = GARBAGE_DATA;
			return (data->return_value);
		}
		map_as_string++;
	}
	return (data->return_value);
}

t_return_value	import_and_prepare_map(t_file_data *data,
		char *map_as_string)
{
	if (data->elements_found != 6)
	{
		if (data->elements_found == 0)
			data->return_value = NO_ELEMENT_FOUND;
		else
			data->return_value = MISSING_ELEMENTS;
		return (data->return_value);
	}
	if (get_map_amount_of_lines(data, map_as_string) == MAP_CONTENT_NOT_VALID)
		return (data->return_value);
	if (get_player_position(
			data, map_as_string, SPAWN_DIRECTION) != OK)
		return (data->return_value);
	if (check_symbols_in_map(data,
			map_as_string) == GARBAGE_DATA)
		return (data->return_value);
	if (check_map_does_not_contain_empty_lines(data,
			map_as_string) == MAP_CONTAINS_EMPTY_LINE)
		return (data->return_value);
	transfer_remaining_string_to_map_array(data, map_as_string);
	return (data->return_value);
}
