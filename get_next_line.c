/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:40:51 by asando            #+#    #+#             */
/*   Updated: 2025/05/13 22:14:15 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_store(char *chr_stored, char *buff)
{
	char	*result;

	if (!chr_stored)
	{
		chr_stored = malloc(1 * sizeof(char));
		if (!chr_stored)
			return (NULL);
		chr_stored[0] = '\0';
	}
	result = ft_strjoin(chr_stored, buff);
	if (buff)
		free(buff);
	if (result == NULL)
	{
		free(chr_stored);
		return (NULL);
	}
	if (chr_stored)
		free(chr_stored);
	return (result);
}

static char	*ft_find_line(char *str)
{
	char	*line;
	int		size;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		size = i + 2;
	else
		size = i + 1;
	line = malloc(size * sizeof(char));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(line, str, size);
	return (line);
}

static int	end_of_file(char *str, int i)
{
	if (str[i] == '\n')
	{
		if (!str[i + 1])
			return (1);
	}
	return (0);
}

static char	*ft_clean_storage(char *str)
{
	char	*result;
	int		size;
	int		i;
	int		eof;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	eof = end_of_file(str, i);
	if (!str[i] || eof)
	{
		free(str);
		return (NULL);
	}
	size = ft_strlen(str) - (i + 1);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(result, &str[i + 1], size + 1);
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buff;
	ssize_t		n_char;
	char		*line;
	char		*temp;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = NULL;
	while (!temp)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		n_char = read(fd, buff, BUFFER_SIZE);
		if (n_char == 0 || n_char < 0)
		{
			free(buff);
			break ;
		}
		buff[n_char] = '\0';
		temp = ft_strchr(buff, '\n');
		storage = ft_store(storage, buff);
		if (!storage)
			return (NULL);
	}
	if (n_char <= 0 && !storage)
		return (NULL);
	line = ft_find_line(storage);
	storage = ft_clean_storage(storage);
	return (line);
}
