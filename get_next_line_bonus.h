/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 01:05:59 by anonymous     #+#    #+#                 */
/*   Updated: 2020/12/11 13:35:31 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>

int				get_next_line(int fd, char **line);
int				ft_strchr(char *str, char c);
char			*ft_strcjoin(char *s1, char *s2);
char			*ft_memmove(char *dest, char *src);
char			*ft_bzero(char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *s);
#endif
