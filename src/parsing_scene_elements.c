/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:20:11 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/12 21:17:53 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_value	get_symbol_texture(char **symbol_type, char *symbol_content)
{
	size_t	length;

	length = 0;
	symbol_content = remove_blankspaces(symbol_content);
	while (symbol_content[length]
		&& symbol_content[length] != '\n')
		length++;
	if (*symbol_type)
		return (DOUBLE);
	*symbol_type = (char *)ft_calloc(length + 1, sizeof(char));
	if (!*symbol_type)
		return (MALLOC_FAIL);
	ft_strlcpy(*symbol_type, symbol_content, length + 1);
	return (SYMBOL_FOUND);
}

t_value	find_and_get_element(char *symbol, t_file_data *data)
{
	t_value	return_value;

	symbol = remove_blankspaces(symbol);
	return_value = SYMBOL_NOT_FOUND;
	if (!ft_strncmp("NO ", symbol, 3))
		return_value = get_symbol_texture(&data->north, symbol + 3);
	if (!ft_strncmp("SO ", symbol, 3))
		return_value = get_symbol_texture(&data->south, symbol + 3);
	if (!ft_strncmp("WE ", symbol, 3))
		return_value = get_symbol_texture(&data->west, symbol + 3);
	if (!ft_strncmp("EA ", symbol, 3))
		return_value = get_symbol_texture(&data->est, symbol + 3);
	if (!ft_strncmp("F ", symbol, 2))
		return_value = get_symbol_texture(&data->floor, symbol + 2);
	if (!ft_strncmp("C ", symbol, 2))
		return_value = get_symbol_texture(&data->ceiling, symbol + 2);
	if (return_value == MALLOC_FAIL)
		data->return_value = MALLOC_FAIL;
	if (return_value == DOUBLE)
		data->return_value = DOUBLE;
	if (return_value == SYMBOL_FOUND)
		data->symbols_found++;
	if (data->symbols_found == SYMBOLS_NEEDED)
		return (ALL_SYMBOLS_FOUND);
	return (return_value);
}

t_value	no_empty_lines(t_file_data *data, char *map_as_string)
{
	bool	empty_line;

	empty_line = false;
	while (*map_as_string)
	{
		if (*map_as_string != ' ' && *map_as_string != '\n')
			empty_line = false;
		if (*map_as_string == '\n' && empty_line)
		{
			data->return_value = MAP_EMPTY_LINE;
			return (data->return_value);
		}
		empty_line = (*map_as_string == '\n');
		map_as_string++;
	}
	return (data->return_value);
}

t_value	get_symbols_and_map(t_file_data *data)
{
	char	*symbol_starts;
	char	*symbol_ends;

	symbol_starts = data->file_to_string;
	while (symbol_starts && *symbol_starts
		&& data->symbols_found < SYMBOLS_NEEDED)
	{
		symbol_starts = remove_blankspaces(symbol_starts);
		symbol_ends = ft_strchr(symbol_starts, '\n');
		if (symbol_starts != symbol_ends)
		{
			if (*symbol_starts == '1' || *symbol_starts == '0'
				|| find_and_get_element(symbol_starts, data) == MALLOC_FAIL)
				break ;
		}
		symbol_starts = symbol_ends;
		if (symbol_starts && *symbol_starts)
			symbol_starts++;
	}
	while (symbol_starts && *symbol_starts == '\n')
		symbol_starts++;
	if (data->return_value == OK)
		import_and_prepare_map(data, symbol_starts);
	return (data->return_value);
}
