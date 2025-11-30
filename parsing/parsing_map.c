/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:32:48 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:32:50 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	ft_isspace_new(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (true);
	return (false);
}

t_data	*ft_strtrim_array(t_data *ret)
{
	int		i;
	char	*str;

	i = 0;
	while (ret->h.file[i])
	{
		str = ft_strtrim(ret->h.file[i], " \t\n\v\f\r");
		if (!str)
			ft_free_printf(ret, "Allocation error\n");
		free(ret->h.file[i]);
		ret->h.file[i] = str;
		i++;
	}
	return (ret);
}

int	ft_checkdecimal(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 15)
	{
		count += ft_checkdecimal(n / 16);
		count++;
	}
	else
		count++;
	return (count);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	save;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		save = str[i];
		str[i] = str[j];
		str[j] = save;
		i++;
		j--;
	}
	return (str);
}
