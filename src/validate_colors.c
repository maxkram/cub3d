/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:23:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/30 01:00:59 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static int	contains_two_commas(char *str)
{
    int comma_count = 0;
    const char *ptr = str;

    while (*ptr) {
        if (*ptr == ',') {
            comma_count++;
        }
        ptr++;
    }

    return (comma_count == 2);
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
