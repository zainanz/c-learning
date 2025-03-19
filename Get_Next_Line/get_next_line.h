/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:03:28 by zali              #+#    #+#             */
/*   Updated: 2025/03/19 14:23:11 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int search_str);
char	*ft_strjoin(char *s1, char *s2);

#endif
