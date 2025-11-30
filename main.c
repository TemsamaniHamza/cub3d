/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okachkac <okachkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:01:14 by okachkac          #+#    #+#             */
/*   Updated: 2025/02/26 14:32:59 by okachkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (argc == 2)
	{
		data = ft_parse(argv[1]);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "cub3d");
		init_map(&data, i, j);
		load_textures(&data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_hook(data.win, 2, 1L << 0, key_press, &data);
		mlx_loop_hook(data.mlx, render_frame, &data);
		mlx_loop(data.mlx);
	}
}

void	init_map(t_data *data, int i, int j)
{
	while (data->maps[++i] != NULL)
	{
		j = -1;
		while (data->maps[i][++j] != '\0')
		{
			if (data->maps [i][j] == 'N' || data->maps [i][j] == 'S' || \
				data->maps [i][j] == 'W' || data->maps [i][j] == 'E')
			{
				data->px = j + 0.5;
				data->py = i + 0.5;
				if (data->maps [i][j] == 'N')
					data->p_angle = 3 * M_PI / 2;
				else if (data->maps [i][j] == 'S')
					data->p_angle = M_PI / 2;
				else if (data->maps [i][j] == 'W')
					data->p_angle = M_PI;
				else if (data->maps [i][j] == 'E')
					data->p_angle = 0;
				data->maps[i][j] = '0';
			}
		}
	}
}
