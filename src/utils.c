/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:22:47 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/10 01:57:34 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

char	*skip_leading_white_spaces(char	*string)
{
	while (string && *string != '\0'
		&& (ft_isspace(*string) || *string == '\t'))
		++string;
	return (string);
}

void	initialize_struct(t_file_data *structure_pointer)
{
	ft_bzero(structure_pointer, sizeof(*structure_pointer));
}

void	print_parse_error_2(t_return_value error)
{
	if (error == NO_SYMBOLS)
		printf("Error\nWrong format of cub file\n");
	if (error == WRONG_PLAYER_DATA)
		printf("Error\nWrong player data\n");
	if (error == WRONG_DATA)
		printf("Error\nGarbage map data\n");
	if (error == MAP_EMPTY_LINE)
		printf("Error\nEmpty line in the map\n");
	if (error == OPEN_WALL)
		printf("Error\nOpen wall\n");
	if (error == WRONG_COLORS)
		printf("Error\nWrong RGB\n");
	if (error == DOUBLE)
		printf("Error\nDuplicates\n");
}

void	print_parse_error(t_return_value error)
{
	if (error == MALLOC_FAIL)
		printf("Error\nMemory issues\n");
	if (error == NEED_CUB)
		printf("Error\nNeed a .cub file\n");
	if (error == EMPTY_FILE)
		printf("Error\nEmpty file\n");
	if (error == FILE_OPEN_FAIL)
		printf("Error\nCannot open the file\n");
	if (error == WRONG_MAP_CONTENT)
		printf("Error\nWrong content\n");
	if (error == WRONG_ARGUMENT)
		printf("Error\nWrong arguments\n");
	if (error == MISSING_SYMBOL)
		printf("Error\nMissed the map's elements\n");
	else
		print_parse_error_2(error);
}

void	clean_up_parsing(t_file_data *data)
{
	int	i;

	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	free(data->floor_color);
	free(data->ceiling_color);
	free(data->file_content_as_string);
	if (data->map_as_array)
	{
		i = 0;
		while (data->map_as_array[i])
			free(data->map_as_array[i++]);
		free(data->map_as_array);
	}
}
