/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:40:51 by asando            #+#    #+#             */
/*   Updated: 2025/05/06 12:13:08 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	char			buff[BUFFER_SIZE];
	int				i;
	char			c;
	static ssize_t	n_char;

	while (c != '\n')
	{
		n_char = read(fd, buff, sizeof(buff));
		if (n_char == 0)
		{
			// do something
		}
		// this condition doesnt stop if n_char less then BUFFER_SIZE
		while (i < BUFFER_SIZE)
		{
			if (buff[i] == '\n')
				// do something
			i++;
		}
	}
	//null if failed
	return (line);
}
