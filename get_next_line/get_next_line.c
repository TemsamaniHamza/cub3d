/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <htemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:46:39 by htemsama          #+#    #+#             */
/*   Updated: 2024/04/04 17:27:48 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_check_new_line(int fd, char *reminder)
{
	char	*new_line_checker;
	int		read_bytes;

	new_line_checker = malloc(BUFFER_SIZE + 1);
	if (!new_line_checker)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr(reminder, '\n') == 0 && read_bytes > 0)
	{
		read_bytes = read(fd, new_line_checker, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(new_line_checker);
			return (NULL);
		}
		new_line_checker[read_bytes] = '\0';
		reminder = ft_strjoin_gnl(reminder, new_line_checker);
	}
	free(new_line_checker);
	return (reminder);
}

char	*ft_clean_line(char *reminder)
{
	char	*output;
	int		i;

	i = 0;
	if (!reminder[i])
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	output = (char *)malloc(sizeof(char) * (i + 2));
	if (!output)
		return (NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
	{
		output[i] = reminder[i];
		i++;
	}
	if (reminder[i] == '\n')
	{
		output[i] = reminder[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_set_reminder(char *reminder)
{
	int		i;
	int		j;
	char	*new_reminder;

	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (NULL);
	}
	new_reminder = (char *)malloc(sizeof(char) * (ft_strlen(reminder) - i + 1));
	if (!new_reminder)
		return (NULL);
	i++;
	j = 0;
	while (reminder[i])
		new_reminder[j++] = reminder[i++];
	new_reminder[j] = '\0';
	free(reminder);
	return (new_reminder);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*reminder[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024 || BUFFER_SIZE > 2147483647)
		return (0);
	reminder[fd] = ft_check_new_line(fd, reminder[fd]);
	if (!reminder[fd])
		return (NULL);
	output = ft_clean_line(reminder[fd]);
	reminder[fd] = ft_set_reminder(reminder[fd]);
	return (output);
}
