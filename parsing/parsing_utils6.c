/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:36:14 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:36:15 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_decimal_to_hex(int str)
{
	char	*hex;
	int		len;
	char	*ret;

	hex = "0123456789ABCDEF";
	len = ft_checkdecimal(str);
	if (str <= 15)
	{
		ret = malloc(3);
		ret[0] = '0';
		ret[1] = hex[str % 16];
		ret[2] = '\0';
		return (ret);
	}
	ret = malloc(len + 1);
	ft_decimal_to_hex2(str, ret, hex);
	ret = ft_strrev(ret);
	return (ret);
}

int	ft_power(int n)
{
	int	i;
	int	total;

	i = 1;
	total = 1;
	if (n == 0)
		return (1);
	if (n == 1)
		return (16);
	if (n > 1)
	{
		while (n >= i)
		{
			total *= 16;
			i++;
		}
		return (total);
	}
	return (-1);
}

int	ft_hex_position(char c)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int	ft_hex_to_decimal(char *str)
{
	int		len;
	int		p;
	int		total;

	len = ft_strlen(str) - 1;
	p = 0;
	total = 0;
	while (len >= 0)
	{
		total = total + (ft_hex_position(str[len]) * ft_power(p));
		len--;
		p++;
	}
	return (total);
}

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
