/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:40:51 by asando            #+#    #+#             */
/*   Updated: 2025/05/06 12:56:37 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE];
	int				i;
	char			c;
	static ssize_t	n_char;
	char			*line;

	i = 0;
	while (c != '\n')
	{
		n_char = read(fd, buff, sizeof(buff));
		if (n_char <= 0)
		{
			// do something
		}
		// this condition doesnt stop if n_char less then BUFFER_SIZE
		while (i < BUFFER_SIZE)
		{
			c = buff[i];
			if (c == '\n')
				// do something
			i++;
		}
	}
	//null if failed
	return (line);
}
