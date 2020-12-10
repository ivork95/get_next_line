/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 17:27:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/09 17:46:37 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char buff[BUFFER_SIZE + 1];
	int ret;

	ret = 1;
	*line = calloc(1 ,1);
	while(ret)
	{
		if (!*buff)
		{
			ret = read(fd, buff, BUFFER_SIZE);
			buff[ret] = '\0'; 
		}
		if (ret < 0)
			return (-1);
		*line = ft_strcjoin(*line, buff, '\n');
		if (ft_strchr(buff, '\n'))
		{
			ft_memmove(buff, buff + (ft_strchr(buff, '\n') + 1));
			return (1);
		}
		ft_bzero(buff);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line[100];
	int		ret;
	// int		count = 0;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("failed to open file \n");
	if (fd == -1)
		return (0);
	while ((ret = get_next_line(fd, line)) && argc)
	{
		printf("return gnl = %d & line = %s\n", ret, *line);
		free(*line);
		// count++;
		// if (count == 2)
		// 	break;
	}
	printf("return gnl = %d & line = %s\n", ret, *line);
	free(*line);
	return (0);
}
