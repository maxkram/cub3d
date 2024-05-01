/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:10:58 by mkramer           #+#    #+#             */
/*   Updated: 2024/05/01 00:56:08 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	loop_hook(void *data_param)
{
	t_data	*d;

	d = (t_data *)data_param;
	update_player_location(d);
	render(d);
}

void	key_hook(mlx_key_data_t keydata, void *data_param)
{
	t_data	*d;

	d = (t_data *)data_param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_exit(d, 0);
}

void	close_hook(void *data_param)
{
	t_data	*d;

	d = (t_data *)data_param;
	clean_exit(d, 0);
}
