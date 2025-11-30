/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:04:00 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/22 01:04:01 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_double_printf(char **line, t_data *ret, char *msg)
{
	free_double_array(line);
	ft_free_printf(ret, msg);
}

void	ft_check_info_extension(t_data *ret)
{
	int	i;

	i = ft_strlen(ret->tex_paths[TEX_EAST]);
	if (ret->tex_paths[TEX_EAST][i - 1] != 'm'
		|| ret->tex_paths[TEX_EAST][i - 2] != 'p'
		|| ret->tex_paths[TEX_EAST][i - 3] != 'x'
		|| ret->tex_paths[TEX_EAST][i - 4] != '.')
		ft_free_printf(ret, "texture doesn't end with '.xpm'");
	i = ft_strlen(ret->tex_paths[TEX_NORTH]);
	if (ret->tex_paths[TEX_NORTH][i - 1] != 'm'
		|| ret->tex_paths[TEX_NORTH][i - 2] != 'p'
		|| ret->tex_paths[TEX_NORTH][i - 3] != 'x'
		|| ret->tex_paths[TEX_NORTH][i - 4] != '.')
		ft_free_printf(ret, "texture doesn't end with '.xpm'");
	i = ft_strlen(ret->tex_paths[TEX_SOUTH]);
	if (ret->tex_paths[TEX_SOUTH][i - 1] != 'm'
		|| ret->tex_paths[TEX_SOUTH][i - 2] != 'p'
		|| ret->tex_paths[TEX_SOUTH][i - 3] != 'x'
		|| ret->tex_paths[TEX_SOUTH][i - 4] != '.')
		ft_free_printf(ret, "texture doesn't end with '.xpm'");
	check_west_texture(ret);
}

void	check_west_texture(t_data *ret)
{
	int	i;

	i = ft_strlen(ret->tex_paths[TEX_WEST]);
	if (ret->tex_paths[TEX_WEST][i - 1] != 'm'
		|| ret->tex_paths[TEX_WEST][i - 2] != 'p'
		|| ret->tex_paths[TEX_WEST][i - 3] != 'x'
		|| ret->tex_paths[TEX_WEST][i - 4] != '.')
		ft_free_printf(ret, "texture doesn't end with '.xpm'");
}

char	**ft_handle_color2(t_data *ret, int i)
{
	char	*str;
	char	*temp;
	char	**ss;

	str = ft_strdup(&ret->h.file[i][2]);
	temp = str;
	str = ft_strtrim(str, " \t\n\v\f\r");
	free(temp);
	ft_handle_color4(ret, str);
	ss = ft_split(str, ',');
	i = 0;
	while (ss[i])
	{
		temp = ss[i];
		ss[i] = ft_strtrim(ss[i], " \t\n\v\f\r");
		free(temp);
		i++;
	}
	free(str);
	return (ss);
}

char	*ft_handle_color3(char **ss, char *temp)
{
	char	*save;

	save = ft_strjoin(ss[0], ss[1]);
	temp = save;
	save = ft_strjoin(save, ss[2]);
	free(temp);
	return (save);
}
