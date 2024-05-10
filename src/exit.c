/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:10:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/10 02:40:22 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	exit_bad_argc(void)
{
	printf("Error with arguments\nIt must something like that: \
		 ./cub3D ./map.cub\n");
	exit(1);
}

void	clean_struct_4_map(t_file_data *data)
{
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->est);
	free(data->floor);
	free(data->ceiling);
	free(data->file_to_string);
}
