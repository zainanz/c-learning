/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:42:08 by zali              #+#    #+#             */
/*   Updated: 2025/03/17 19:27:44 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# define HEX "0123456789abcdef"

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}	t_list;

// ---------------------- Memory funcs ---------------------------
void	bzero(void *s, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t n);
void	*ft_memccpy(void *destination, const void *source, int c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memmove(void *destination, const void *source, size_t num);
// Mem - Part 2
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
// ----------------- String mani/info ----------------------------
int		ft_atoi(char *s);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strlen(char *str);
char	*ft_strdup(const char *s);
// Str - Part 2
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_strsplit(char const *s, char c);
char	*ft_strtrim(char const *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
// strcpy
char	*ft_strcpy(char *destination, const char *source);
char	*ft_strncpy(char *destination, const char *source, size_t n);
// strstr
char	*ft_strstr(char *s1, char *s2);
char	*ft_strnstr(char *s1, char *s2, size_t len);
// strchr
char	*ft_strrchr(const char *str, int search_str);
char	*ft_strchr(const char *str, int search_str);
// strcmp
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
// strcat
char	*ft_strncat(char *destination, const char *source, size_t num);
size_t	ft_strlcat(char *destination, const char *source, size_t num);
char	*ft_strcat(char *destination, const char *source);
// Converts int into a String
char	*ft_itoa(int n);
// --------------- is (true false) funcs --------------------
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isprint(char c);
int		ft_isdigit(char c);
int		ft_isascii(char c);
int		ft_isalpha(int c);
int		ft_isalnum(char c);
// List Functions
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void const *content);
t_list	*ft_lstlast(t_list *lst);

// My personal funcs
int		ft_count_words(char *s, char c);
int		ft_iswhitespace(int c);
int		ft_get_word_len(char *s, char c);
int		ft_pow(int n, int power);
int		ft_total_digits(int n);
char	*ft_get_word(char *s, char c);
void	ft_print_hex_with_upcase(int c, int upcase);
int		ft_print_base(long int nbr, int upcase, int base);
int		ft_base_size(long int nbr, int upcase, int base);

#endif
