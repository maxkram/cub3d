/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:23:06 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/13 02:56:42 by mkramer          ###   ########.fr       */
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

t_value	check_color_strings(t_file_data *data)
{
	if (!has_2_commas(data->ceiling)
		|| !has_2_commas(data->floor))
	{
		data->return_value = WRONG_COLORS;
		return (WRONG_COLORS);
	}
	return (OK);
}
