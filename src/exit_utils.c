/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:10:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/29 03:13:51 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	exit_invalid_argc(void)
{
	ft_putstr_fd("Error\nUsage: ./cub3D map.cub\n", 2);
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
