/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 00:37:26 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/12 21:51:10 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int		ft_read(int fd, char *buff, int ret)
{
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret < 0)
		return (-1);
	buff[fd][ret] = '\0';
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	ret = 1;
	*line = malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	*line[0] = '\0';
	while (ret)
	{
		if (!*buff[fd])
			ret = ft_read(fd, buff[fd], ret);
		if (ret < 0)
			return (-1);
		*line = ft_strcjoin(*line, buff[fd]);
		if (*line == NULL)
			return (-1);
		if (ft_memmove(buff[fd], buff[fd] + (ft_strchr(buff[fd], '\n'))))
			return (1);
		ft_bzero(buff[fd]);
	}
	return (0);
}
