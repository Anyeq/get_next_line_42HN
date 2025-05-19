/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:41:04 by asando            #+#    #+#             */
/*   Updated: 2025/05/19 08:21:11 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
ssize_t	read_fd(int fd, char *buff, char **storage);
int		err_check(int fd, char **storage);
char	*ft_find_line(char **storage, ssize_t byte_read);
char	*ft_clean_storage(char *storage, char **line);
char	*ft_store_char(char *storage, char *buff, int *new_line_found);
#endif
