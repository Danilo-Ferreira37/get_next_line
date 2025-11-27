/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:11:42 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/19 13:17:27 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str, char *buffer)
{
	char	*d;
	size_t	i;
	size_t	j;

	d = malloc(sizeof(char) * (strlen_newline(str) + strlen_newline(buffer)
				+ 1));
	if (!d)
		return (free(str), NULL);
	i = 0;
	while (str && str[i] != '\0' && i < strlen_newline(str))
	{
		d[i] = str[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0' && j < strlen_newline(buffer))
		d[i++] = buffer[j++];
	free(str);
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
