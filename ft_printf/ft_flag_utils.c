/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:17 by zali              #+#    #+#             */
/*   Updated: 2025/03/13 11:27:00 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_char(int c, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}

int	ft_display_hashtag_sign(int upcase)
{
	if (upcase)
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	return (2);
}

void	ft_add_char_if(int condition, int zero, size_t n)
{
	if (!condition)
		return ;
	if (zero)
		ft_add_char('0', n);
	else
		ft_add_char(' ', n);
}

int	ft_add_sign(int nbr, t_print_data *data)
{
	if (data->sign)
	{
		if (nbr >= 0)
			write(1, "+", 1);
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
	}
	else if (data->space)
	{
		write(1, " ", 1);
	}
	return (nbr);
}
