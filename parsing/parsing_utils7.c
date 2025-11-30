/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:36:48 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:36:49 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_printf_2(t_data *ret)
{
	int	i;

	if (ret->h.map_copy != NULL)
	{
		i = 0;
		while (ret->h.map_copy[i] != NULL)
		{
			free(ret->h.map_copy[i]);
			i++;
		}
		free(ret->h.map_copy);
	}
	if (ret->maps != NULL)
	{
		i = 0;
		while (ret->maps[i] != NULL)
		{
			free(ret->maps[i]);
			i++;
		}
		free(ret->maps);
	}
	ft_free_printf_3(ret);
}

void	ft_free_printf_3(t_data *ret)
{
	int	i;

	if (ret->h.file != NULL)
	{
		i = 0;
		while (ret->h.file[i] != NULL)
		{
			free(ret->h.file[i]);
			i++;
		}
		free(ret->h.file);
	}
}

bool	ft_line_valid(char *map, int j)
{
	int	i;

	i = ft_strlen(map);
	if (i > j)
		return (true);
	else
		return (false);
}
