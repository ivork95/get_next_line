/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 17:27:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/04 14:42:54 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
#define BUFF_SIZE 32

int		get_next_line(int fd, char **line)
{
	printf("test|\n");
	char buff[BUFF_SIZE + 1];
	int ret;
	printf("test2|\n");
	*line = malloc(sizeof(char) * 1);
	*line[0] = '\0';
	printf("test3|\n");
	memset(buff, 0, BUFF_SIZE + 1);
	printf("test4|\n");
	printf("temp = %s|\n", temp.content);
	printf("index = %zu|\n", temp.index);
	if (!temp.content)
	{
		printf("test5|\n");
		temp.content = calloc(BUFF_SIZE + 1, sizeof(char));
		temp.index = 0;
		ret = 1;
	}
	else
	{
		printf("test6|\n");
		*line = ft_strcjoin(*line, temp.content, temp.index);
		printf("line = %s|\n", *line);
		if (strchr(temp.content + temp.index, '\n'))
			return (1);
	}
	while (ret)
	{
		ret = read(fd, buff, BUFF_SIZE);
		printf("temp = %s|\n", temp.content);
		printf("ret = %d|\n", ret);
		ft_strlcpy(temp.content, buff, BUFF_SIZE);
		printf("temp = %s|\n", temp.content);
		temp.index = 0;
		*line = ft_strcjoin(*line, temp.content, temp.index);
		printf("line = %s|\n", *line);
		printf("index = %zu|\n", temp.index);
		if (strchr(temp.content, '\n'))
			return (1);
		temp.index = 0;
		memset(temp.content, 0, BUFF_SIZE + 1);
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line[100];
	int		ret;
	int		count = 0;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("failed to open file \n");
	if (fd == -1)
		return (0);
	while ((ret = get_next_line(fd, line)) && argc)
	{
		printf("return gnl = %d & line = %s\n", ret, *line);
		free(*line);
		count++;
		if (count == 3)
			break;
	}
	// printf("return gnl = %d & line = %s\n", ret, *line);
	// free(*line);
	return (0);
}
