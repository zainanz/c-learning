/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:50:34 by zali              #+#    #+#             */
/*   Updated: 2025/03/09 15:56:28 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	t_print_data	*data;

	data = ft_init_pdata();
	ft_display_data(data);
	ft_data_parse("-010casd", data);
	ft_display_data(data);
}
