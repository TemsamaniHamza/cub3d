/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:47:49 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/26 14:24:34 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_wall_column(t_data *d, int x, t_ray_params *rp)
{
	t_texture		*tex;
	t_wall_data		wall;
	int				y;
	int				tex_y;
	char			*pix;

	tex = get_wall_texture(d, rp);
	wall = prepare_wall_data(d, rp, tex);
	y = wall.draw_start - 1;
	while (++y < wall.draw_end)
	{
		tex_y = (int)wall.tex_pos % tex->height;
		pix = tex->addr + (tex_y * tex->line_len + wall.tex_x * (tex->bpp / 8));
		my_mlx_pixel_put(d, x, y, *(unsigned int *)pix);
		wall.tex_pos += wall.step;
	}
	y = -1;
	while (++y < wall.draw_start)
		my_mlx_pixel_put(d, x, y, d->h.celling);
	y = wall.draw_end;
	while (y < SCREEN_H)
	{
		my_mlx_pixel_put(d, x, y, d->h.floor);
		y++;
	}
}

t_wall_data	prepare_wall_data(t_data *d, t_ray_params *rp, t_texture *tex)
{
	t_wall_data	w;
	double		wall_x;

	w.line_height = (int)(SCREEN_H / rp->perp_dist);
	w.draw_start = -w.line_height / 2 + SCREEN_H / 2;
	if (w.draw_start < 0)
		w.draw_start = 0;
	w.draw_end = w.line_height / 2 + SCREEN_H / 2;
	if (w.draw_end >= SCREEN_H)
		w.draw_end = SCREEN_H - 1;
	if (rp->side == 0)
		wall_x = d->py + rp->raw_dist * rp->dir_y;
	else
		wall_x = d->px + rp->raw_dist * rp->dir_x;
	wall_x -= floor(wall_x);
	w.tex_x = (int)(wall_x * tex->width);
	if (w.tex_x < 0)
		w.tex_x = 0;
	if (w.tex_x >= tex->width)
		w.tex_x = tex->width - 1;
	if ((rp->side == 0 && rp->dir_x > 0) || (rp->side == 1 && rp->dir_y < 0))
		w.tex_x = tex->width - w.tex_x - 1;
	w.step = (double)tex->height / w.line_height;
	w.tex_pos = (w.draw_start - SCREEN_H / 2 + w.line_height / 2) * w.step;
	return (w);
}

t_texture	*get_wall_texture(t_data *d, t_ray_params *rp)
{
	if (rp->side == 0)
	{
		if (rp->dir_x > 0)
			return (&d->textures[TEX_EAST]);
		else
			return (&d->textures[TEX_WEST]);
	}
	else
	{
		if (rp->dir_y > 0)
			return (&d->textures[TEX_SOUTH]);
		else
			return (&d->textures[TEX_NORTH]);
	}
}
