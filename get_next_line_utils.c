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

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t			srclen;
	unsigned int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	srclen = strlen(src);
	if (n == 0)
	{
		return (srclen);
	}
	while ((src[i] != '\0') && (i < n - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (n != 0)
		dest[i] = '\0';
	return (srclen);
}


char	*ft_strcjoin(char *s1, char *s2, size_t n)
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
	while (s2[n] != '\0' && s2[n] != '\n')
	{
		newstr[i] = s2[n];
		i++;
		n++;
	}
	newstr[i] = '\0';
	return (newstr);
}
