/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:42:08 by zali              #+#    #+#             */
/*   Updated: 2025/02/17 07:58:06 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
// String mani/info
int		ft_atoi(char *s);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strstr(char *s1, char *s2);
char	*ft_strnstr(char *s1, char *s2, int n, size_t len);
char	*ft_strrchr(const char *str, int search_str);
char	*ft_strchr(const char *str, int search_str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncat(char *destination, const char *source, size_t num);
size_t	ft_strlcat(char *destination, const char *source, size_t num);
char	*ft_strcat(char *destination, const char *source);
int		ft_strlen(char *str);
// is (true false) funcs
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isprint(char c);
int		ft_isdigit(char c);
int		ft_isascii(char c);
int		ft_isalpha(char c);
int		ft_isalnum(char c);

#endif
