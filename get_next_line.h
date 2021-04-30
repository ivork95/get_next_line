/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 10:39:09 by anonymous     #+#    #+#                 */
/*   Updated: 2021/04/30 16:55:49 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

int				get_next_line(int fd, char **line);
int				ft_strchr(char *str, char c);
char			*ft_strcjoin(char *s1, char *s2);
char			*ft_memmove(char *dest, char *src);
char			*ft_bzero(char *str);
size_t			ft_strlen(const char *s);
#endif
