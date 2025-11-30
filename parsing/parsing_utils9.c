/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:09 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/22 01:04:10 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_decimal_to_hex2(int str, char *ret, char *hex)
{
	int	i;

	i = 0;
	while (str > 15)
	{
		ret[i] = hex[str % 16];
		str = str / 16;
		i++;
	}
	if (str > 0)
	{
		ret[i] = hex[str % 16];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_free_printf_succ(t_data *ret)
{
	if (!ret)
		return ;
	if (ret->h.no != NULL)
		free(ret->h.no);
	if (ret->h.so != NULL)
		free(ret->h.so);
	if (ret->h.ea != NULL)
		free(ret->h.ea);
	if (ret->h.we != NULL)
		free(ret->h.we);
	if (ret->tex_paths[TEX_NORTH] != NULL)
		free(ret->tex_paths[TEX_NORTH]);
	if (ret->tex_paths[TEX_SOUTH] != NULL)
		free(ret->tex_paths[TEX_SOUTH]);
	if (ret->tex_paths[TEX_WEST] != NULL)
		free(ret->tex_paths[TEX_WEST]);
	if (ret->tex_paths[TEX_EAST] != NULL)
		free(ret->tex_paths[TEX_EAST]);
	ft_free_printf_2(ret);
	exit(0);
}

void	ft_init_textures(t_data *ret)
{
	ret->textures[0].img = NULL;
	ret->textures[1].img = NULL;
	ret->textures[2].img = NULL;
	ret->textures[3].img = NULL;
}

void	ft_handle_color4(t_data *ret, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == ',')
		{
			free(str);
			ft_free_printf(ret, "rgb is inccorect");
		}
		else if (str[i] == ',' && str[i + 1] == '\0')
		{
			free(str);
			ft_free_printf(ret, "rgb is inccorect");
		}
		else if (str[i] == ',' && str[i + 1] == ',')
		{
			free(str);
			ft_free_printf(ret, "rgb is inccorect");
		}
		else
			i++;
	}
	return ;
}
