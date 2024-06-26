/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:23:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/02 01:24:58 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	has_2_commas(char *str)
{
	int			count;
	const char	*ptr;

	count = 0;
	ptr = str;
	while (*ptr)
	{
		if (*ptr == 44)
			count++;
		ptr++;
	}
	return (count == 2);
}

t_return_value	validate_color_strings(t_file_data *data)
{
	if (!has_2_commas(data->ceiling_color)
		|| !has_2_commas(data->floor_color))
	{
		data->return_value = WRONG_COLORS;
		return (WRONG_COLORS);
	}
	return (OK);
}
