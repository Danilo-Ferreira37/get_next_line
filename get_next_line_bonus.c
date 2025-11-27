/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:35:06 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/12 15:53:09 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][(BUFFER_SIZE > 0) * BUFFER_SIZE];
	ssize_t		n_bytes;
	char		*str;

	str = NULL;
	if ((fd >= FD_MAX || fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	while (!has_newline(str))
	{
		if (buffer[fd][0] == '\0')
		{
			n_bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (n_bytes < 0)
				return (free(str), NULL);
			if (n_bytes == 0)
				break ;
		}
		str = ft_strjoin(str, buffer[fd]);
		if (!str)
			return (NULL);
		clean_buffer(buffer[fd]);
	}
	return (str);
}

/* int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("txt.1", O_RDONLY);
	fd2 = open("txt.2", O_RDONLY);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	return (0);
} */
