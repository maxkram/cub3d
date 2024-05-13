/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:20:45 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/12 22:26:30 by mkramer          ###   ########.fr       */
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

t_value	create_buffers(char **line_buffer, t_file_data *data)
{
	*line_buffer = ft_strdup("");
	free(data->file_to_string);
	data->file_to_string = ft_strdup("");
	if (!*line_buffer || !data->file_to_string)
	{
		data->return_value = MALLOC_FAIL;
		free(*line_buffer);
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
