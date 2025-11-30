/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:33:48 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:33:49 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_walls(char **line, int i, int flag, t_data *ret)
{
	int	j;

	j = 0;
	if (flag == 1)
	{
		while (line[i][j] != '\0')
		{
			if (line[i][j] == '1' || ft_isspace_new(line[i][j]) == true)
				j++;
			else
				free_double_printf(line, ret, "there is a problem in the wall");
		}
		return (1);
	}
	if (flag == 0)
	{
		if (line[i][j] == '1' && line[i][ft_strlen(line[i]) - 1] == '1')
			return (1);
		else
			free_double_printf(line, ret, "there is a problem in the wall");
	}
	return (-1);
}

bool	is_a_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

t_data	*ft_check_the_content(char **map_cpy, t_data *ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_cpy[i] && map_cpy[i][0] != 0)
	{
		while (map_cpy[i][j])
		{
			if (is_a_player(map_cpy[i][j]) == true)
				ret->h.nbr_player++;
			if (map_cpy[i][j] == '1' || map_cpy[i][j] == '0'
				|| ft_isspace_new(map_cpy[i][j]) == true
				|| is_a_player(map_cpy[i][j]) == true)
				j++;
			else
				free_double_printf(map_cpy, ret, "unwanted charachter!");
		}
		j = 0;
		i++;
	}
	free_double_array(map_cpy);
	if (ret->h.nbr_player != 1)
		ft_free_printf(ret, "there is more or less than one player");
	return (ret);
}

t_data	*ft_handle_map(t_data *ret, int i)
{
	int		j;
	int		k;
	char	**map_cpy;

	j = ft_find_first_m(ret, i);
	k = how_many_lines_left(ret, j);
	map_cpy = ft_cpy_map(ret, k, j);
	if (map_cpy[0] == NULL)
		ft_free_printf(ret, "Map is missing");
	k = ft_check_bellow_map_walls(map_cpy, ret);
	ret = ft_check_the_content(map_cpy, ret);
	ret->maps = malloc((k + 1) * sizeof(char *));
	i = 0;
	while (k > 0)
	{
		ret->maps[i] = ft_strdup(ret->h.map_copy[j]);
		i++;
		j++;
		k--;
	}
	ret->maps[i] = NULL;
	i = 0;
	return (ret);
}

t_data	*ft_set_check_info(t_data *ret)
{
	int	i;

	i = 0;
	while (ret->h.file[i])
	{
		ret = ft_set_info(ret, i);
		if (ft_check_flag(ret) == true)
		{
			ft_check_info_extension(ret);
			i++;
			ret = ft_handle_map(ret, i);
			return (ret);
		}
		i++;
	}
	return (ret);
}
