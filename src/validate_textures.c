/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:23:37 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/01 00:58:16 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static t_return_value	validate_one_texture(mlx_texture_t *texture)
{
	if (texture->height != texture->width)
	{
		ft_putstr_fd("Error\nTexture is not square\n", 2);
		return (FAILURE);
	}
	if (texture->height < TEXTURE_SIZE_MIN
		|| texture->height > TEXTURE_SIZE_MAX)
	{
		ft_putstr_fd("Error\nTexture is not between ", 2);
		ft_putnbr_fd(TEXTURE_SIZE_MIN, 2);
		ft_putstr_fd(" and ", 2);
		ft_putnbr_fd(TEXTURE_SIZE_MAX, 2);
		ft_putstr_fd(" pixels in side length\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	validate_textures(t_data *render_data)
{
	int	failure_total;

	failure_total = 0;
	failure_total += (int)validate_one_texture(render_data->texture.north);
	failure_total += (int)validate_one_texture(render_data->texture.east);
	failure_total += (int)validate_one_texture(render_data->texture.south);
	failure_total += (int)validate_one_texture(render_data->texture.west);
	if (failure_total > 0)
		clean_exit(render_data, 1);
}
