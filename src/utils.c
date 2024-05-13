/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:22:47 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/12 23:40:44 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

char	*remove_blankspaces(char	*string)
{
	while (string && *string != '\0'
		&& (ft_isspace(*string) || *string == '\t'))
		++string;
	return (string);
}

void	create_struct(t_file_data *structure_pointer)
{
	ft_bzero(structure_pointer, sizeof(*structure_pointer));
}

void	print_parse_error_2(t_value error)
{
	if (error == NO_SYMBOLS)
		printf("\033[1;31mError\nWrong format of cub file\033[0m\n");
	if (error == WRONG_PLAYER_DATA)
		printf("\033[1;31mError\nWrong player data\033[0m\n");
	if (error == WRONG_DATA)
		printf("\033[1;31mError\nGarbage map data\033[0m\n");
	if (error == MAP_EMPTY_LINE)
		printf("\033[1;31mError\nEmpty line in the map\033[0m\n");
	if (error == OPEN_WALL)
		printf("\033[1;31mError\nOpen wall\033[0m\n");
	if (error == WRONG_COLORS)
		printf("\033[1;31mError\nWrong RGB\033[0m\n");
	if (error == DOUBLE)
		printf("\033[1;31mError\nDuplicates\033[0m\n");
}

void	print_parse_error(t_value error)
{
	if (error == MALLOC_FAIL)
		printf("\033[1;31mError\nMemory issues\033[0m\n");
	if (error == NEED_CUB)
		printf("\033[1;31mError\nNeed a .cub file\033[0m\n");
	if (error == EMPTY_FILE)
		printf("\033[1;31mError\nEmpty file\033[0m\n");
	if (error == FILE_OPEN_FAIL)
		printf("\033[1;31mError\nCannot open the file\033[0m\n");
	if (error == WRONG_MAP_CONTENT)
		printf("\033[1;31mError\nWrong content\033[0m\n");
	if (error == WRONG_ARGUMENT)
		printf("\033[1;31mError\nWrong arguments\033[0m\n");
	if (error == MISSING_SYMBOL)
		printf("\033[1;31mError\nMissed the map's elements\033[0m\n");
	else
		print_parse_error_2(error);
}

void	clean_up_parsing(t_file_data *data)
{
	int	i;

	free(data->north);
	free(data->south);
	free(data->west);
	free(data->est);
	free(data->floor);
	free(data->ceiling);
	free(data->file_to_string);
	if (data->map_to_array)
	{
		i = 0;
		while (data->map_to_array[i])
			free(data->map_to_array[i++]);
		free(data->map_to_array);
	}
}
