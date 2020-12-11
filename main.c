/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 01:42:41 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/11 01:42:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line);
int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open file \n");
		return (0);
	}
	ret = 1;
	while (ret && argc)
	{
		ret = get_next_line(fd, &line);
		printf(" %d | %s\n", ret, line);
		free(line);
	}
	return (0);
}
