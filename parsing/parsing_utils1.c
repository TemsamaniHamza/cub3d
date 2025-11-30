/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:33:02 by htemsama          #+#    #+#             */
/*   Updated: 2025/03/20 00:33:04 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_overflow(char *nptr)
{
	int	i;

	i = 0;
	if (ft_overflow_2(nptr, i) == 1)
		return (1);
	if (ft_overflow_3(nptr, i) == 1)
		return (1);
	if (ft_strlen(nptr) < 10 && nptr[i] != '-')
		return (0);
	if (nptr[i] == '-' && ft_strlen(nptr) == 11)
	{
		if (ft_strncmp(nptr, "-2147483648", 12) > 0)
			return (1);
	}
	if (ft_strncmp(nptr, "2147483647", 11) > 0)
		return (1);
	return (0);
}

int	ft_overflow_3(char *nptr, int i)
{
	if (ft_strlen(nptr) > 10 && nptr[i] != '-')
	{
		if (nptr[i] == '0')
		{
			while (nptr[i] == '0' && nptr[i] != '\0')
				i++;
			if (nptr[i] == '\0')
				return (0);
			if (ft_strlen(&nptr[i]) > 9)
			{
				if (ft_strncmp(&nptr[i], "2147483647", 11) > 0)
					return (1);
			}
			return (0);
		}
		return (1);
	}
	return (0);
}

int	ft_overflow_2(char *nptr, int i)
{
	if (nptr[i] == '-' && ft_strlen(nptr) > 11)
	{
		if (nptr[i + 1] == '0')
		{
			i++;
			while (nptr[i] == '0' && nptr[i] != '\0')
				i++;
			if (nptr[i] == '\0')
				return (0);
			if (ft_strlen(&nptr[i]) > 9)
			{
				if (ft_strncmp(&nptr[i], "2147483648", 11) > 0)
					return (1);
			}
			return (0);
		}
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	ft_atoi_rgbx(char *nptr)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	if (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		return (-1);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (270);
		i++;
	}
	if (ft_overflow(nptr) == 1)
		return (270);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (ft_isdigit(nptr[i]) != 1 && nptr[i] != '\0')
		return (270);
	return (result * sign);
}
