/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:13:46 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/27 12:50:38 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Lê uma linha do descritor de arquivo fd.
 *        Preserva conteúdo entre chamadas usando buffer estático.
 *
 * @param fd Descritor de arquivo.
 * @return Linha lida (inclui '\n' se presente), ou NULL em erro/fim.
 */
char	*get_next_line(int fd)
{
	static char	buffer[(BUFFER_SIZE > 0) * BUFFER_SIZE];
	char		*str;
	ssize_t		n_bytes;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!has_newline(str))
	{
		if (buffer[0] == '\0')
		{
			n_bytes = read(fd, buffer, BUFFER_SIZE);
			if (n_bytes == -1)
				return (free(str), NULL);
			if (n_bytes == 0)
				break ;
		}
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		clean_buffer(buffer);
	}
	return (str);
}

/* int	main(void)
{
	int		fd;
	//int		i;
	char	*line;

	fd = open("txt.1", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	for (i = 0; i < 8; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	return (0);
} */
/*
int	main(void)
{
	char    *line;

	while ((line = get_next_line(0)) != NULL)
	{
		write(1, line, strlen_newline(line));
		free(line);
	}
	line = get_next_line(0);
	printf("%s", line);
	free(line);
	return (0);
}*/
