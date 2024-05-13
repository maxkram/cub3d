/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:22:12 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/13 02:09:36 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

uint32_t	abgr_to_rgba(uint32_t agbr)
{
	return((agbr & 0xFF) << 24) | ((agbr & 0xFF00) << 8)
		| ((agbr & 0xFF0000) >> 8) | ((agbr & 0xFF000000) >> 24);
}

uint32_t	get_texture_pixel(mlx_texture_t *texture, uint32_t x, uint32_t y)
{
	uint32_t	color;
	uint32_t	offset;

	if (x >= texture->width || y >= texture->height)
		return (0);
	offset = ((y * texture->width) + x);
	color = ((uint32_t *)texture->pixels)[offset];
	return (abgr_to_rgba(color));
}

void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
		mlx_put_pixel(image, x, y, color);
}

double	deg_to_rad(double degrees)
{
	return (degrees * M_PI / 180.0);
}

void	floor_ceiling_render(t_data	*d)
{
	size_t	i;
	size_t	half_pixels;

	i = 0;
	half_pixels = (WINDOW_WIDTH * WINDOW_HEIGHT) * 0.5;
	while (i < half_pixels)
		mlx_put_pixel(d->img, i++, 0, d->color.ceiling);
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT)
		mlx_put_pixel(d->img, i++, 0, d->color.floor);
}
