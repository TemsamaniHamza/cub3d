/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:51:24 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/19 10:48:04 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_data *d)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		d->textures[i].img = mlx_xpm_file_to_image(d->mlx, d->tex_paths[i],
				&d->textures[i].width, &d->textures[i].height);
		if (!d->textures[i].img)
		{
			close_window(d);
			ft_free_printf(d, "Failed to load texture");
		}
		d->textures[i].addr = mlx_get_data_addr(d->textures[i].img,
				&d->textures[i].bpp, &d->textures[i].line_len, \
				&d->textures[i].endian);
		i++;
	}
}
