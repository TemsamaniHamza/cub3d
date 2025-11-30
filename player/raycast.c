/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:53:07 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/26 14:44:18 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycast(t_data *d)
{
	int				x;
	t_ray_params	rp;
	double			ray_angle;

	d->img = mlx_new_image(d->mlx, SCREEN_W, SCREEN_H);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->line_len, &d->endian);
	x = 0;
	while (x < SCREEN_W)
	{
		ray_angle = (d->p_angle - FOV / 2) + (x / (double)SCREEN_W) * FOV;
		init_ray_params(&rp, d, ray_angle);
		perform_dda(d, &rp);
		calculate_wall_dis(&rp, d, ray_angle);
		draw_wall_column(d, x, &rp);
		x++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
}

void	init_ray_params(t_ray_params *rp, t_data *d, double ray_angle)
{
	init_ray_direction(rp, d, ray_angle);
	init_ray_steps(rp, d);
}

void	perform_dda(t_data *d, t_ray_params *rp)
{
	while (1)
	{
		if (rp->side_dist_x < rp->side_dist_y)
		{
			rp->side_dist_x += rp->delta_dist_x;
			rp->map_x += rp->step_x;
			rp->side = 0;
		}
		else
		{
			rp->side_dist_y += rp->delta_dist_y;
			rp->map_y += rp->step_y;
			rp->side = 1;
		}
		if (d->maps[rp->map_y][rp->map_x] == '1')
			break ;
	}
}

void	calculate_wall_dis(t_ray_params *rp, t_data *d, double ray_angle)
{
	double	raw_dist;

	if (rp->side == 0)
		raw_dist = (rp->map_x - d->px + (1 - rp->step_x) / 2) / rp->dir_x;
	else
		raw_dist = (rp->map_y - d->py + (1 - rp->step_y) / 2) / rp->dir_y;
	rp->raw_dist = raw_dist;
	rp->perp_dist = raw_dist * cos(ray_angle - d->p_angle);
}

int	render_frame(t_data *data)
{
	raycast(data);
	return (0);
}
