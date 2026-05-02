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
    size_t len1 = strlen_newline(str);
    size_t len2 = strlen_newline(buffer);
    char *d = malloc(len1 + len2 + 1);
    size_t i = 0;
    size_t j = 0;

    if (!d)
        return (free(str), NULL);

    while (str && i < len1)
    {
        d[i] = str[i];
        i++;
    }

    while (j < len2)
        d[i++] = buffer[j++];

    d[i] = '\0';
    free(str);
    return d;
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
