/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:58:40 by zali              #+#    #+#             */
/*   Updated: 2025/03/10 16:36:36 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define HEX "0123456789abcdef"
//
# include <stdarg.h>
# include "libft.h"
//

typedef struct print_data
{
	int	width;
	int	precision;
	char	format;
	int	left_just;
	int	space;
	int	zero;
	int	sign;
	int	hashtag;
}	print_data;

int	ft_print_base(long int nbr, int upcase, int base);
int	ft_print_mem(void *ptr);
int	ft_print_int(int nbr);
int	ft_print_str(char *str);
int	ft_print_char(int c);

#endif
