/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:10:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/12 21:01:33 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	exit_bad_argc(void)
{
	printf("\033[1;31mWrong arguments\nUse ./cub3D ./map.cub\033[0m\n");
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
