/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:40:12 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/04 11:40:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_memmove(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_bzero(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int		ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strcjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	n;

	if (!s1 || !s2)
		return (0);
	newstr = (char*)malloc(strlen(s1) + strlen(s2) + 1);
	i = 0;
	n = 0;
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0' && s2[n] != '\n')
	{
		newstr[i] = s2[n];
		i++;
		n++;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}
