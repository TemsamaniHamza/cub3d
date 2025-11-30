/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:31:31 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:31:33 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_printf(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	ft_free_printf(t_data *ret, char *msg)
{
	if (!ret)
	{
		ft_printf(msg);
		return ;
	}
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
	ft_printf(msg);
}

int	ft_isspace(int c)
{
	if (c <= 32)
		return (0);
	return (1);
}

t_data	ft_parse(char *str)
{
	int		fd;
	int		i;
	t_data	ret;

	ft_init_flag(&ret);
	fd = open(str, O_RDWR, 0777);
	if (fd == -1)
		ft_free_printf(&ret, "The file is incorrect");
	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
		ft_free_printf(&ret, "the file does not end with '.cub'");
	ret.h.file = malloc(BUFFER_SIZE + 1);
	if (!ret.h.file)
		ft_free_printf(&ret, "Allocation failed");
	i = 0;
	ret.h.file[i] = get_next_line(fd);
	if (ret.h.file[i] == NULL)
		ft_free_printf(&ret, "The given file is probably empty");
	while (ret.h.file[i] != NULL)
	{
		i++;
		ret.h.file[i] = get_next_line(fd);
	}
	return (ft_parse_file(&ret, str), ret);
}
