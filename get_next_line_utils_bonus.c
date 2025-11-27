/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:35:09 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/27 12:57:52 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *line, char *buffer)
{
	char	*d;
	size_t	i;
	size_t	j;

	d = malloc(sizeof(char) * (strlen_newline(line) + strlen_newline(buffer)
				+ 1));
	if (!d)
		return (free(line), NULL);
	i = 0;
	while (line && line[i] && i < strlen_newline(line))
	{
		d[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0' && j < strlen_newline(buffer))
		d[i++] = buffer[j++];
	free(line);
	d[i] = '\0';
	return (d);
}

void	clean_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (buffer[j])
		buffer[j++] = '\0';
}

size_t	strlen_newline(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	has_newline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
