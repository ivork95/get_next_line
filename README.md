# get_next_line

## Description

The aim of this project is to make you code a function that returns a line
ending with a newline, read from a file descriptor. <br>

## Usage

```c
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
	while (ret > 0 && argc)
	{
		ret = get_next_line(fd, &line);
		printf(" %d | %s\n", ret, line);
		free(line);
	}
	return (0);
}

```
* return ``1`` if it filled ``line``
* return ``0`` when it reaches the end of file
* return ``-1`` if it encountered any error while reading the file
