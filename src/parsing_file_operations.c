/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:10:29 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/10 02:46:54 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_value	open_and_check_file(t_file_data *data,
		const char **path)
{
	data->fd = open(path[1], O_RDONLY);
	if (data->fd == -1)
	{
		data->return_value = FILE_OPEN_FAIL;
		close(data->fd);
	}
	return (data->return_value);
}

t_value	concat_temp_to_string(t_file_data *data,
		char *line)
{
	char	*temp;

	temp = ft_strdup(data->file_to_string);
	if (!temp)
	{
		data->return_value = MALLOC_FAIL;
		return (data->return_value);
	}
	free(data->file_to_string);
	data->file_to_string = ft_strjoin(temp, line);
	free(temp);
	if (!(data->file_to_string))
		data->return_value = MALLOC_FAIL;
	return (data->return_value);
}

t_value	map_to_string(t_file_data *data, const char **path)
{
	char	*line_buffer;

	if ((open_and_check_file(data, path) == FILE_OPEN_FAIL)
		|| (initialize_string_buffers(&line_buffer, data) == MALLOC_FAIL))
		return (data->return_value);
	while (line_buffer)
	{
		free(line_buffer);
		line_buffer = get_next_line(data->fd);
		if (!line_buffer)
			break ;
		if (concat_temp_to_string(data,
				line_buffer) == MALLOC_FAIL)
		{
			free(line_buffer);
			break ;
		}
	}
	if (line_buffer)
		free(line_buffer);
	close(data->fd);
	return (data->return_value);
}
//it checks the file type ".cub". If it's not correct
//it assigns the error code in the file_data structure

t_value	check_file_type(t_file_data *data, const char **path_to_file)
{
	const char	*path;
	char		*end4;
	size_t		len;

	path = path_to_file[1];
	end4 = NULL;
	if (*path)
	{
		len = ft_strlen(path);
		end4 = ft_substr(path, len - 4, 4);
		if (ft_strncmp(".cub", end4, 4))
			data->return_value = NEED_CUB;
		free(end4);
	}
	return (data->return_value);
}

t_value	check_scene_demands(t_file_data *data)
{
	if ((get_scene_elements_and_map(data) != OK)
		|| (validate_color_strings(data) != OK)
		|| (get_colors(data) != OK))
		return (data->return_value);
	return (data->return_value);
}
