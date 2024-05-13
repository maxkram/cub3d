/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:23:37 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/02 00:48:08 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_value	check_texture(mlx_texture_t *texture)
{
	const char	*sq_err;
	const char	*sz_err;

	sq_err = "\033[1;31mTexture is not a square\033[0m\n";
	sz_err = "\033[1;31mTexture is not between %d and %d pixels\033[0m\n";
	if (texture->height != texture->width)
	{
		printf("%s", sq_err);
		return (1);
	}
	if (texture->height < 32 || texture->height > 64)
	{
		printf(sz_err, 32, 64);
		return (1);
	}
	return (0);
}

void	check_all_textures(t_data *render_data)
{
	int	all_failures;

	all_failures = 0;
	all_failures += check_texture(render_data->texture.north);
	all_failures += check_texture(render_data->texture.east);
	all_failures += check_texture(render_data->texture.south);
	all_failures += check_texture(render_data->texture.west);
	if (all_failures > 0)
		clean_and_exit(render_data, 1);
}
