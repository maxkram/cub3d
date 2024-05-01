/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:10:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/30 22:48:11 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	exit_bad_argc(void)
{
	printf("Error with arguments\nIt must something like that: ./cub3D ./map.cub\n");
	exit(EXIT_FAILURE);
}

void	free_file_data_not_map(t_file_data *data)
{
	free(data->north_texture);
	free(data->south_texture);
free(data->west_texture);
	free(data->east_texture);
	free(data->floor_color);
	free(data->ceiling_color);
	free(data->file_content_as_string);
}
