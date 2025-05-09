/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:40:51 by asando            #+#    #+#             */
/*   Updated: 2025/05/09 13:26:48 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_store(const char *chr_stored, const char *buff)
{
	char	*result;

	result = ft_strjoin(chr_stored, buff);
	if (result == NULL)
	{
		if (chr_stored)
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
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		size = i + 2;
	else
		size = i + 1;
	line = malloc(size * sizeof(char));
	if (!line)
		return (NULL);
	while (j < size)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_clean_storage(char *str)
{
	char	*result;
	int		size;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	size = ft_strlen(str) - i;
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (str[i])
		ft_strlcpy(result, &str[i + 1], size + 1);
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	ssize_t		n_char;
	char		*temp;
	char		*line;
	static char	*storage;

	temp = NULL;
	while (temp == NULL)
	{
		n_char = read(fd, buff, sizeof(buff));
		if (n_char <= 0) //this need to be checked
			break ;
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
