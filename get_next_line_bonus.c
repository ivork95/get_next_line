/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 00:37:26 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/11 13:55:10 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	int			ret;

	if (BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	*line = malloc(sizeof(char));
	*line[0] = '\0';
	while (ret)
	{
		if (!*buff[fd])
		{
			ret = read(fd, buff[fd], BUFFER_SIZE);
			buff[fd][ret] = '\0';
			if (ret < 0)
				return (-1);
		}
		*line = ft_strcjoin(*line, buff[fd]);
		if (ft_memmove(buff[fd], buff[fd] + (ft_strchr(buff[fd], '\n'))))
			return (1);
		ft_bzero(buff[fd]);
	}
	return (0);
}
