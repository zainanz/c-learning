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

#include "printf.h"

void	ft_pdata_set_default(print_data *data)
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

print_data	*ft_init_pdata(void)
{
	print_data	*data;

	data = malloc(sizeof(print_data));
	if (!data)
		return (NULL);
	ft_pdata_set_default(data);
	return (data);
}

void	ft_data_parse(char *format, print_data *data)
{
	int	i;

	i = 0;
	while (format[i])
	{
	if (format[i] == '-')
		data->left_just = 1;
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
		data->precision = atoi(&format[i]);
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
}
