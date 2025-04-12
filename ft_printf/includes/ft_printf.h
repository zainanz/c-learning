/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:58:40 by zali              #+#    #+#             */
/*   Updated: 2025/03/13 11:36:46 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define HEX "0123456789abcdef"
//
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
//

typedef struct print_data
{
	int		width;
	int		precision;
	char	format;
	int		left_just;
	int		space;
	int		zero;
	int		sign;
	int		hashtag;
}		t_print_data;

int		ft_printf(const char *str, ...);
int		ft_print_base_core(long int nbr, int upcase, int base,
			t_print_data *data);
int		ft_print_mem(void *ptr, t_print_data *data);
int		ft_put_hex(uintptr_t n);
int		ft_print_int(int nbr);
int		ft_print_str(char *str, t_print_data *data);
int		ft_print_char(int c, t_print_data *data);
int		ft_data_parse(char *format, t_print_data *data);
int		ft_display_hashtag_sign(int upcase);
int		ft_add_sign(int nbr, t_print_data *data);
void	ft_pdata_set_default(t_print_data *data);
void	ft_add_char(int c, size_t n);
void	ft_add_char_if(int condition, int zero, size_t n);
void	ft_display_data(t_print_data *data);
t_print_data				*ft_init_pdata(void);
//Helper
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);
int		ft_print_base(long int nbr, int upcase, int base);
void	ft_print_hex_with_upcase(int c, int upcase);
int		ft_base_size(long int nbr, int upcase, int base);
int		ft_toupper(int c);
int		ft_islower(int c);

#endif
