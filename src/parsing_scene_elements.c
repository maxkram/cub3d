/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:20:11 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/10 02:21:56 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_return_value	get_element_texture(char **element_type, char *element_content)
{
	size_t	length;

	length = 0;
	element_content = skip_leading_white_spaces(element_content);
	while (element_content[length]
		&& element_content[length] != '\n')
		length++;
	if (*element_type)
		return (DOUBLE);
	*element_type = (char *)calloc(length + 1, sizeof(char));
	if (!*element_type)
		return (MALLOC_FAIL);
	ft_strlcpy(*element_type, element_content, length + 1);
	return (SYMBOL_FOUND);
}

/**
 * @brief Find and extract map elements from a string.
 *
 * This function identifies and extracts various map elements from a string,
 * such as textures, floor color, and ceiling color.
 *
 * @param element The string to analyze and extract elements from.
 * @param data A pointer to the t_file_data structure.
 * @return The exit code indicating success or failure.
 */
static t_return_value	find_and_get_element(char *element, t_file_data *data)
{
	t_return_value	return_value;

	element = skip_leading_white_spaces(element);
	return_value = SYMBOL_NOT_FOUND;
	if (ft_strncmp("NO ", element, 3) == 0)
		return_value = get_element_texture(&data->north_texture, element + 3);
	if (ft_strncmp("SO ", element, 3) == 0)
		return_value = get_element_texture(&data->south_texture, element + 3);
	if (ft_strncmp("WE ", element, 3) == 0)
		return_value = get_element_texture(&data->west_texture, element + 3);
	if (ft_strncmp("EA ", element, 3) == 0)
		return_value = get_element_texture(&data->east_texture, element + 3);
	if (ft_strncmp("F ", element, 2) == 0)
		return_value = get_element_texture(&data->floor_color, element + 2);
	if (ft_strncmp("C ", element, 2) == 0)
		return_value = get_element_texture(&data->ceiling_color, element + 2);
	if (return_value == MALLOC_FAIL)
		data->return_value = MALLOC_FAIL;
	if (return_value == DOUBLE)
		data->return_value = DOUBLE;
	if (return_value == SYMBOL_FOUND)
		data->elements_found++;
	if (data->elements_found == SYMBOLS_NEEDED)
		return (ALL_SYMBOLS_FOUND);
	return (return_value);
}

/**
 * @brief Check if the map contains empty lines.
 *
 * This function checks if the map contains empty lines and sets the appropriate
 * error code in the t_file_data structure if it does.
 *
 * @param data A pointer to the t_file_data structure.
 * @param map_as_string The string representing the map.
 * @return The exit code indicating success or failure.
 */
t_return_value
	check_map_does_not_contain_empty_lines(t_file_data *data,
										char *map_as_string)
{
	t_bool	empty_line;

	empty_line = FALSE;
	while (*map_as_string != '\0')
	{
		if (*map_as_string != ' ' && *map_as_string != '\n')
			empty_line = FALSE;
		else if (*map_as_string == '\n')
		{
			if (empty_line)
			{
				data->return_value = MAP_EMPTY_LINE;
				return (data->return_value);
			}
			empty_line = TRUE;
		}
		map_as_string++;
	}
	return (data->return_value);
}

/**
 * @brief Get map elements from the input scene description.
 *
 * This function parses the input scene description and extracts map elements
 * such as textures, floor color, ceiling color, and the map itself.
 *
 * @param data A pointer to the t_file_data structure.
 * @return The exit code indicating success or failure.
 */
t_return_value
	get_scene_elements_and_map(t_file_data *data)
{
	char	*element_starts;
	char	*element_ends;

	element_starts = data->file_content_as_string;
	while (element_starts && *element_starts != '\0'
		&& data->elements_found < SYMBOLS_NEEDED)
	{
		element_starts = skip_leading_white_spaces(element_starts);
		element_ends = ft_strchr(element_starts, '\n');
		if (element_starts != element_ends)
		{
			if (*element_starts == '1' || *element_starts == '0'
				|| find_and_get_element(element_starts, data) == MALLOC_FAIL)
				break ;
		}
		element_starts = element_ends;
		if (element_starts && *element_starts != '\0')
			element_starts++;
	}
	while (element_starts
		&& *element_starts != '\0' && *element_starts == '\n')
		element_starts++;
	if (data->return_value == OK)
		import_and_prepare_map(data, element_starts);
	return (data->return_value);
}
