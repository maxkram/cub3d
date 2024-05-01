/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:21:02 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/01 00:59:25 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	init_ray_base_values(t_data *d, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir.x = d->player.dir.x + d->player.plane.x * ray->cam_x;
	ray->dir.y = d->player.dir.y + d->player.plane.y * ray->cam_x;
	ray->map.x = (int)d->player.pos.x;
	if (ray->map.x < 0 || ray->map.x >= d->map.width)
		exit(1);
	ray->map.y = (int)d->player.pos.y;
	if (ray->map.y < 0 || ray->map.y >= d->map.height)
		exit(1);
}

void	init_ray_delta(t_ray *ray)
{
	ray->delta_dist.x = 123456789;
	if (ray->dir.x != 0)
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = 123456789;
	if (ray->dir.y != 0)
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

void	init_ray_side_distance(t_data *d, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (d->player.pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - d->player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (d->player.pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - d->player.pos.y)
			* ray->delta_dist.y;
	}
}
