/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:51:31 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/26 14:21:11 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SCREEN_W && y >= 0 && y < SCREEN_H)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *) dst = color ;
	}
}

int	close_window(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (data->textures[i].img)
			mlx_destroy_image(data->mlx, data->textures[i].img);
		i++;
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	ft_free_printf_succ(data);
	exit(0);
}
