/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 17:27:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/02 15:21:13 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 32

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return (dest + (i));
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			i++;
			str = malloc(sizeof(char)* strlen((s) + i) + 1);
			while (s[i] != '\0')
			{
				str[j] = s[i];
				i++;
				j++;
			}
			str[j] = '\0';
			return (str);
		}
		i++;
	}
	return (0);
}

char	*ft_strcjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	newstr = (char*)malloc(strlen(s1) + strlen(s2) + 1);
	i = 0;
	j = 0;
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	get_next_line(int fd, char **line)
{
	static char *temp;
	static char buff[BUF_SIZE + 1];
	int ret;

	ret = 1;
	printf("temp before = %s\n", temp);
	while (ret)
	{
		ret = read(fd, buff, BUF_SIZE);
		buff[ret] = '\0';
		printf("buff = %s\n", buff);
		printf("temp = %s\n", temp);
		if (temp != 0)
		{
			ft_memccpy(*line, temp, '\n', BUF_SIZE);
			free(temp);
			*temp = 0;
			printf("line in = %s\n", *line);
		}
		printf("test\n");
		*line = ft_strcjoin(*line, buff);
		printf("line = %s\n", *line);
		temp = ft_strchr(buff, '\n');
		printf("temp2 = %s\n", temp);
		if (temp != 0)
			return(1);
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
		printf("return gnl = %d & line = %s\n", ret, *line);
		free(*line);
	}
	printf("return gnl = %d & line = %s\n", ret, *line);
	free(*line);
	return (0);
}
