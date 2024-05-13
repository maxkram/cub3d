/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:20:45 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/12 22:02:54 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_value	count_the_lines(t_file_data *data, char *map)
{
	data->number_of_lines++;
	while (*map)
	{
		if (*map == '\n')
			data->number_of_lines++;
		map++;
	}
	if (data->number_of_lines < 3)
		data->return_value = WRONG_MAP_CONTENT;
	return (data->return_value);
}

int	max_length(char *map)
{
	int		max_len;
	int		len;
	char	*start;
	char	*end;

	max_len = 0;
	start = map;
	while (*start)
	{
		end = ft_strchr(start, '\n');
		if (!end)
			end = start + ft_strlen(start);
		len = end - start;
		if (len > max_len)
			max_len = len;
		start = end;
		if (start && *start)
			start++;
	}
	return (max_len);
}

/**
 * @brief Initialize string buffers for file content and line.
 *
 * This function initializes the string buffers for storing the file's content
 * and each line of the file. It allocates memory for these buffers and handles
 * memory allocation failures by setting the appropriate error code.
 *
 * @param line A pointer to the line buffer.
 * @param file_to_string A pointer to the file content buffer.
 * @param data A pointer to the t_file_data structure.
 * @return The exit code indicating success or failure.
 */
t_value	initialize_string_buffers(char **line_buffer, t_file_data *data)
{
	*line_buffer = ft_strdup("");
	if (data->file_to_string)
		free(data->file_to_string);
	data->file_to_string = ft_strdup("");
	if (!*line_buffer || !data->file_to_string)
	{
		data->return_value = MALLOC_FAIL;
		if (*line_buffer)
			free(*line_buffer);
		if (data->file_to_string)
			free(data->file_to_string);
		close(data->fd);
	}
	return (data->return_value);
}

t_bool	ft_is_numerical(char *str)
{
	if (!str || !str[0])
		return (FALSE);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (FALSE);
	}
	return (TRUE);
}
