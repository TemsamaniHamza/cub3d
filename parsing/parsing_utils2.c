/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:33:28 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:33:30 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_flag(t_data *ret)
{
	ret->h.flg_celling = 0;
	ret->h.flg_ea = 0;
	ret->h.flg_floor = 0;
	ret->h.flg_no = 0;
	ret->h.flg_so = 0;
	ret->h.flg_we = 0;
	ret->h.nbr_player = 0;
	ret->h.file = NULL;
	ret->h.map_copy = NULL;
	ret->maps = NULL;
	ret->mlx = NULL;
	ret->win = NULL;
	ret->img = NULL;
	ret->addr = NULL;
	ret->maps = NULL;
	ret->h.ea = NULL;
	ret->h.we = NULL;
	ret->h.no = NULL;
	ret->h.so = NULL;
	ret->tex_paths[TEX_NORTH] = NULL;
	ret->tex_paths[TEX_SOUTH] = NULL;
	ret->tex_paths[TEX_WEST] = NULL;
	ret->tex_paths[TEX_EAST] = NULL;
	ft_init_textures(ret);
}

t_data	*copy_of_file(t_data *ret, char *str)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(str, O_RDWR, 0777);
	if (fd == -1)
		ft_free_printf(ret, "The file is incorrect");
	ret->h.map_copy = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!ret->h.file)
		ft_free_printf(ret, "Allocation failed");
	ret->h.map_copy[i] = get_next_line(fd);
	if (ret->h.map_copy[i] == NULL)
		ft_free_printf(ret, "The given file is probably empty");
	while (ret->h.map_copy[i] != NULL)
	{
		i++;
		ret->h.map_copy[i] = get_next_line(fd);
	}
	return (ret);
}

void	ft_check_space(t_data *ret, int i, int j)
{
	int	total;
	int	len;

	total = 0;
	len = 0;
	while (ret->maps[total] != NULL)
		total++;
	len = strlen(ret->maps[i]);
	if (j + 1 < len && ret->maps[i][j + 1] != ' ' && ret->maps[i][j + 1] != '1'
		&& ret->maps[i][j + 1] != '\n')
		ft_free_printf(ret, "invalid map");
	if (j - 1 >= 0 && ret->maps[i][j - 1] != ' ' && ret->maps[i][j - 1] != '1')
		ft_free_printf(ret, "invalid map");
	if (i + 1 < total && ft_line_valid(ret->maps[i + 1], j) == true
		&& ret->maps[i + 1][j] != ' ' && ret->maps[i + 1][j] != '1'
		&& ret->maps[i + 1][j] != '\n')
		ft_free_printf(ret, "invalid map");
	if (i - 1 >= 0 && ft_line_valid(ret->maps[i - 1], j) == true
		&& ret->maps[i - 1][j] != ' ' && ret->maps[i - 1][j] != '1'
		&& ret->maps[i - 1][j] != '\n' )
		ft_free_printf(ret, "invalid map");
}

void	ft_is_map_valid(t_data *ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ret->maps[i])
	{
		while (ret->maps[i][j] != '\0')
		{
			if (ret->maps[i][j] == ' ')
				ft_check_space(ret, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_parse_file(t_data *ret, char *str)
{
	ret = copy_of_file(ret, str);
	ret = ft_strtrim_array(ret);
	ret = ft_set_check_info(ret);
	ft_is_map_valid(ret);
}
