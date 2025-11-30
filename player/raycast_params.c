/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:40:02 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/26 14:46:10 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray_direction(t_ray_params *rp, t_data *d, double ray_angle)
{
	rp->dir_x = cos(ray_angle);
	rp->dir_y = sin(ray_angle);
	rp->map_x = (int)d->px;
	rp->map_y = (int)d->py;
	if (rp->dir_x != 0)
		rp->delta_dist_x = fabs(1 / rp->dir_x);
	else
		rp->delta_dist_x = 1e30;
	if (rp->dir_y != 0)
		rp->delta_dist_y = fabs(1 / rp->dir_y);
	else
		rp->delta_dist_y = 1e30;
}

void	init_ray_steps(t_ray_params *rp, t_data *d)
{
	if (rp->dir_x < 0)
	{
		rp->step_x = -1;
		rp->side_dist_x = (d->px - rp->map_x) * rp->delta_dist_x;
	}
	else
	{
		rp->step_x = 1;
		rp->side_dist_x = (rp->map_x + 1.0 - d->px) * rp->delta_dist_x;
	}
	if (rp->dir_y < 0)
	{
		rp->step_y = -1;
		rp->side_dist_y = (d->py - rp->map_y) * rp->delta_dist_y;
	}
	else
	{
		rp->step_y = 1;
		rp->side_dist_y = (rp->map_y + 1.0 - d->py) * rp->delta_dist_y;
	}
}
