/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_struct_server.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:07:44 by zali              #+#    #+#             */
/*   Updated: 2025/06/24 16:08:31 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_string	*string_init(int size)
{
	static t_string	string;

	if (!string.ptr)
	{
		string.ptr = malloc(sizeof(char) * size);
		if (!string.ptr)
			malloc_error();
		string.size = size;
		string.index = 0;
	}
	return (&string);
}

void	append_to_string(char c)
{
	t_string	*string;

	string = string_init(0);
	string->ptr[string->index] = c;
	string->index++;
}

void	string_end(void)
{
	t_string	*string;

	string = string_init(0);
	write(1, string->ptr, string->size);
	free(string->ptr);
	string->ptr = NULL;
	write(1, "\n", 1);
}
