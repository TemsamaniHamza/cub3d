/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:52:55 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/26 13:46:59 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_position(t_data *d, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_x < 0 || !d->maps[map_y])
		return (0);
	if (map_x >= (int)strlen(d->maps[map_y]) || d->maps[map_y][map_x] == '\0')
		return (0);
	if (d->maps[(int)(y + PADDING)][(int)(x + PADDING)] == '1' ||
		d->maps[(int)(y - PADDING)][(int)(x - PADDING)] == '1' ||
		d->maps[(int)(y + PADDING)][(int)(x - PADDING)] == '1' ||
		d->maps[(int)(y - PADDING)][(int)(x + PADDING)] == '1')
		return (0);
	return (d->maps[map_y][map_x] == '0');
}

void	handle_rotation(int keycode, t_data *d)
{
	if (keycode == XK_Left)
		d->p_angle -= ROT_SPEED;
	else if (keycode == XK_Right)
		d->p_angle += ROT_SPEED;
	if (d->p_angle < 0)
		d->p_angle += 2 * M_PI;
	else if (d->p_angle > 2 * M_PI)
		d->p_angle -= 2 * M_PI;
}

double	get_move_direction(int key, double player_angle)
{
	if (key == XK_w)
		return (player_angle);
	if (key == XK_s)
		return (player_angle + M_PI);
	if (key == XK_a)
		return (player_angle - M_PI_2);
	if (key == XK_d)
		return (player_angle + M_PI_2);
	return (-1);
}

int	handle_movement(int key, t_data *d)
{
	double	new_x;
	double	new_y;
	double	move_dir;

	move_dir = get_move_direction(key, d->p_angle);
	if (key == XK_Left)
		d->p_angle -= ROT_SPEED;
	else if (key == XK_Right)
		d->p_angle += ROT_SPEED;
	if (move_dir != -1)
	{
		new_x = d->px + cos(move_dir) * MOVE_SPEED;
		new_y = d->py + sin(move_dir) * MOVE_SPEED;
		if (is_valid_position(d, new_x, new_y))
		{
			d->px = new_x;
			d->py = new_y;
			return (1);
		}
	}
	return (0);
}

int	key_press(int keycode, t_data *d)
{
	if (keycode == XK_Escape)
		close_window(d);
	handle_movement(keycode, d);
	handle_rotation(keycode, d);
	return (0);
}
