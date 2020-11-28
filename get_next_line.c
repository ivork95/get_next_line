/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 17:27:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/11/27 21:32:34 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	get_next_line(int fd, char **line)
{
	char buff[1];
	int i;

	i = 0;
	*line = malloc(sizeof(char) * 200);
	while(read(fd, buff, 1))
	{
		if(buff[0] == '\n')
			return (1);
		line[0][i] = buff[0];
		i++;

	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line[100];
	int		ret;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("failed to open file \n");
	if (fd == -1)
		return (0);
	while ((ret = get_next_line(fd, line)) && argc)
	{
		printf("%d: %s\n", ret, *line);
		free(*line);
	}
	printf("%d: %s\n", ret, *line);
	free(*line);
	return (0);
}
