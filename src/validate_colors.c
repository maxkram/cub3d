/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:23:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/29 01:23:09 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static int	contains_two_commas(char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count == 2)
		return (1);
	return (0);
}

t_return_value	validate_color_strings(t_file_data *data)
{
	if (!contains_two_commas(data->ceiling_color)
		|| !contains_two_commas(data->floor_color))
	{
		data->return_value = INVALID_COLORS;
		return (INVALID_COLORS);
	}
	return (SUCCESS);
}