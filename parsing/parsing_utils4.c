/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:34:39 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:34:40 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_skip_spaces(char *str, t_data *ret)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (-1);
	else if (str[i] == '1')
		return (i);
	else
	{
		ft_free_printf(ret, "The wall should be all ones");
		return (-1);
	}
}

int	ft_find_first_m(t_data *ret, int i)
{
	while (ret->h.file[i])
	{
		if (ft_skip_spaces(ret->h.file[i], ret) == -1)
			i++;
		else
			break ;
	}
	return (i);
}

int	how_many_lines_left(t_data *ret, int j)
{
	while (ret->h.file[j])
		j++;
	return (j);
}

char	**ft_cpy_map(t_data *ret, int k, int j)
{
	int		i;
	char	**map_cpy;
	char	*copy;

	i = 0;
	map_cpy = (char **)malloc(k * sizeof(char *));
	while (ret->h.file[j])
	{
		copy = ft_strtrim(ret->h.file[j], " \t\n\v\f\r");
		map_cpy[i] = ft_strdup(copy);
		free(copy);
		i++;
		j++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	ft_check_bellow_map_walls(char **map_cpy, t_data *ret)
{
	int	i;
	int	save;

	i = 0;
	while (map_cpy[i] && map_cpy[i][0] == '1')
	{
		if (i == 0)
			i += ft_check_walls(map_cpy, i, 1, ret);
		else if (i > 0)
			i += ft_check_walls(map_cpy, i, 0, ret);
		else
			break ;
	}
	ft_check_walls(map_cpy, i - 1, 1, ret);
	save = i;
	while (map_cpy[i])
	{
		if (map_cpy[i][0] == 0)
			i++;
		else
			free_double_printf(map_cpy, ret, "unwanted charachter !!");
	}
	return (save);
}
