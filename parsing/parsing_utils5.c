/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:35:22 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:35:24 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_handle_color(t_data *ret, int i)
{
	char	**ss;
	char	*save;
	char	*temp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	ss = ft_handle_color2(ret, i);
	while (ss[j])
	{
		k = ft_atoi_rgbx(ss[j]);
		if (k > 255)
			free_double_printf(ss, ret, "rgb is incorrect");
		temp = ss[j];
		ss[j] = ft_decimal_to_hex(k);
		free(temp);
		j++;
	}
	if (j != 3)
		free_double_printf(ss, ret, "there is an error in the rgb color");
	save = ft_handle_color3(ss, temp);
	k = ft_hex_to_decimal(save);
	return (free(save), free_double_array(ss), k);
}

bool	ft_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			return (false);
		i++;
	}
	return (true);
}

t_data	*ft_set_info_two(t_data *ret, int i)
{
	if (ft_strncmp(ret->h.file[i], "EA ", 3) == 0
		&& ft_isspace_new(ret->h.file[i][2]) == true)
	{
		ret->h.flg_ea++;
		ret->h.ea = ft_strdup(&ret->h.file[i][3]);
		ret->tex_paths[TEX_EAST] = ft_strtrim(ret->h.ea, " \t\n\v\f\r");
	}
	else if (ft_strncmp(ret->h.file[i], "F ", 2) == 0)
	{
		ret->h.flg_floor++;
		ret->h.floor = ft_handle_color(ret, i);
	}
	else if (ft_strncmp(ret->h.file[i], "C ", 2) == 0)
	{
		ret->h.flg_celling++;
		ret->h.celling = ft_handle_color(ret, i);
	}
	else if (ft_empty_string(ret->h.file[i]) == false)
		ft_free_printf(ret, "unwanted charachter");
	return (ret);
}

t_data	*ft_set_info(t_data *ret, int i)
{
	if (ft_strncmp(ret->h.file[i], "NO", 2) == 0
		&& ft_isspace_new(ret->h.file[i][2]) == true)
	{
		ret->h.flg_no++;
		ret->h.no = ft_strdup(&ret->h.file[i][3]);
		ret->tex_paths[TEX_NORTH] = ft_strtrim(ret->h.no, " \t\n\v\f\r");
	}
	else if (ft_strncmp(ret->h.file[i], "SO ", 3) == 0
		&& ft_isspace_new(ret->h.file[i][2]) == true)
	{
		ret->h.flg_so++;
		ret->h.so = ft_strdup(&ret->h.file[i][3]);
		ret->tex_paths[TEX_SOUTH] = ft_strtrim(ret->h.so, " \t\n\v\f\r");
	}
	else if (ft_strncmp(ret->h.file[i], "WE ", 3) == 0
		&& ft_isspace_new(ret->h.file[i][2]) == true)
	{
		ret->h.flg_we++;
		ret->h.we = ft_strdup(&ret->h.file[i][3]);
		ret->tex_paths[TEX_WEST] = ft_strtrim(ret->h.we, " \t\n\v\f\r");
	}
	else
		ret = ft_set_info_two(ret, i);
	i++;
	return (ret);
}

bool	ft_check_flag(t_data *ret)
{
	if (ret->h.flg_celling > 1 || ret->h.flg_ea > 1 || ret->h.flg_floor > 1
		|| ret->h.flg_no > 1 || ret->h.flg_so > 1 || ret->h.flg_we > 1)
	{
		ft_free_printf(ret, "There is a duplicate in the map");
		return (false);
	}
	if (ret->h.flg_celling == 1 && ret->h.flg_ea == 1 && ret->h.flg_floor == 1
		&& ret->h.flg_no == 1 && ret->h.flg_so == 1 && ret->h.flg_we == 1)
	{
		return (true);
	}
	return (false);
}
