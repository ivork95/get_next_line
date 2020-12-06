int	get_next_line(int fd, char **line)
{
	static char temp[BUF_SIZE + 1];
	static char buff[BUF_SIZE + 1];
	int i;
	int j;
	int k;
	int ret;

	i = 0;
	j = 0;
	ret = 1;
	*line = calloc(200, sizeof(char));
	while (ret)
	{
		ret = read(fd, buff, BUF_SIZE);
		buff[ret] = '\0';
		k = 0;
		if (*temp)
		{
			memccpy(*line, temp, '\n', BUF_SIZE);
			*temp = 0;
			i = strlen(*line);
		}
		while(buff[k])
		{
			// CHANGE FOR STRCHR
			if (buff[k] == '\n')
			{
				k++;
				while(buff[k])
				{
					temp[j] = buff[k];
					j++;
					k++;
				}
				temp[j] = '\0';
				return (1);
			}
			line[0][i] = buff[k];
			i++;
			k++;
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *temp;
	static char buff[BUF_SIZE + 1];
	int i;
	int j;
	int k;
	int ret;

	i = 0;
	j = 0;
	ret = 1;
	temp = calloc(BUF_SIZE, sizeof(char));
	*line = calloc(200, sizeof(char));
	printf("test\n");
	while (ret)
	{
		printf("test2\n");
		ret = read(fd, buff, BUF_SIZE);
		printf("buff = %s\n", buff);
		printf("test3");
		if(*temp != 0)
		{
			printf("test temp");
			memccpy(*line, temp, '\n', BUF_SIZE);
		}
		printf("test4\n");
		*line = ft_strcjoin(*line, buff);
		printf("line = %s\n", *line);
		temp = ft_strchr(buff, '\n');
		printf("temp = %s\n", temp);
		if (ft_strchr(buff, '\n'))
			return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *temp;
	static char buff[BUF_SIZE + 1];
	int i;
	int ret;

	i = 0;
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
			memccpy(*line, temp, '\n', BUF_SIZE);
			*temp = 0;
			i = strlen(*line);
			printf("line in = %s\n", *line);
		}
		printf("test\n");
		*line = ft_strcjoin(*line, buff);
		printf("line = %s\n", *line);
		free(temp);
		temp = ft_strchr(buff, '\n');
		printf("temp2 = %s\n", temp);
		if (temp != 0)
			return(1);
	}
	return (0);
}

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

int		get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*temp;
	static size_t	index;
	int				ret;

	ret = 1;
	*line = calloc(1, 1);
	buff[BUFF_SIZE] = '\0';
	while (ret)
	{
		if (!temp)
		{
			temp = calloc(BUFF_SIZE, sizeof(char));
			index = 0;
		}
		printf("index = %lu\n", index);
		printf("tempindex = %c|\n", temp[index]);
		if (temp[index] != '\0')
		{
			*line = ft_strcjoin(*line, temp, index);
			if (strchr(&temp[index], '\n'))
			{
				index = (int)(strchr(&temp[index], '\n') - temp) + 1;
				return (1);
			}
			memset(temp, 0, BUFF_SIZE);
			index = 0;
		}
		ret = read(fd, buff, BUFF_SIZE);
		printf("buff = %s\n", buff);
		printf("temp = %s\n", temp);
		printf("line = %s\n", *line);
		strncpy(temp, buff, BUFF_SIZE);
	}
	return (0);
}
