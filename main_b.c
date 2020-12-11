/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 01:43:10 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/11 01:43:10 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int 	fd2;
	int		ret;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	fd2 = open("lines.txt", O_RDONLY);
	if (fd == -1 || fd2 == -1)
	{
		printf("failed to open file \n");
		return (-1);
	}
	ret = 1;
	while (ret && argc)
	{		
		ret = get_next_line(fd, &line);
		printf("%d| line1 = %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d| line1 = %s\n", ret, line);
		free(line);
	}
	return (0);
}
