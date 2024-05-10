/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_and_player_import.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:19:07 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/10 02:45:21 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	fill_player_data(t_file_data *data, char *input_string,
		char player_birth_direct)
{
	data->player_x = data->current_position - data->last_new_line_position - 1;
	data->player_y = data->line_count;
	*data->player_birth_direct = player_birth_direct;
	input_string[data->current_position] = '0';
}

t_value	get_player_position(t_file_data *data,
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
	data->return_value = WRONG_PLAYER_DATA;
	return (data->return_value);
}

t_value	check_symbols_in_map(t_file_data *data,
										char *map_as_string)
{
	while (*map_as_string)
	{
		if (*map_as_string != ' ' && *map_as_string != '0'
			&& *map_as_string != '1' && *map_as_string != '\n')
		{
			data->return_value = WRONG_DATA;
			return (data->return_value);
		}
		map_as_string++;
	}
	return (data->return_value);
}

t_value	import_and_prepare_map(t_file_data *data,
		char *map_as_string)
{
	if (data->symbols_found != 6)
	{
		if (data->symbols_found != 0)
			data->return_value = MISSING_SYMBOL;
		else
			data->return_value = NO_SYMBOLS;
		return (data->return_value);
	}
	if ((get_map_amount_of_lines(data, map_as_string) == WRONG_MAP_CONTENT)
		|| (get_player_position(data, map_as_string, BIRTH_DIRECT) != OK)
		|| (check_symbols_in_map(data, map_as_string) == WRONG_DATA)
		|| (check_map_does_not_contain_empty_lines(data,
				map_as_string) == MAP_EMPTY_LINE))
		return (data->return_value);
	move_string_to_map_array(data, map_as_string);
	return (data->return_value);
}
