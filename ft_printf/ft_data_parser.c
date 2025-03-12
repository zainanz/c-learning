/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:18:31 by zali              #+#    #+#             */
/*   Updated: 2025/03/10 16:51:49 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pdata_set_default(t_print_data *data)
{
	data->width = 0;
	data->precision = -1;
	data->format = 0;
	data->left_just = 0;
	data->space = 0;
	data->zero = 0;
	data->sign = 0;
	data->hashtag = 0;
}

t_print_data	*ft_init_pdata(void)
{
	t_print_data	*data;

	data = malloc(sizeof(t_print_data));
	if (!data)
		return (NULL);
	ft_pdata_set_default(data);
	return (data);
}

void	ft_display_data(t_print_data *data)
{
	ft_putstr("Format: ");
	ft_putchar(data->format);
	ft_putchar('\n');
	ft_putstr("Width: ");
	ft_putnbr(data->width);
	ft_putchar('\n');
	ft_putstr("Precision: ");
	ft_putnbr(data->precision);
	ft_putchar('\n');
	ft_putstr("Left Justify: ");
	ft_putnbr(data->left_just);
	ft_putchar('\n');
	ft_putstr("Space: ");
	ft_putnbr(data->space);
	ft_putchar('\n');
	ft_putstr("Zero: ");
	ft_putnbr(data->zero);
	ft_putchar('\n');
	ft_putstr("Sign: ");
	ft_putnbr(data->sign);
	ft_putchar('\n');
	ft_putstr("Hashtag: ");
	ft_putnbr(data->hashtag);
	ft_putchar('\n');
}

int	ft_data_parse(char *format, t_print_data *data)
{
	int	i;

	i = 1;
	while (format[i])
	{
		if (format[i] == '-')
			data->left_just = 1;
		else if (format[i] == '#')
			data->hashtag = 1;
		else if (format[i] == '0')
			data->zero = 1;
		else if (format[i] == '+')
			data->sign = 1;
		else if (format[i] == ' ')
			data->space = 1;
		else if (format[i] == '%')
			break ;
		else if (ft_isdigit(format[i]))
		{
			data->width = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
			i--;
        	}
		else if (format[i] == '.')
		{
			i++;
			data->precision = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
			i--;
        	}
		else if (ft_isalpha(format[i]))
		{
			data->format = format[i];
			break ;
		}
 		i++;
    	}
	return (i);
}
