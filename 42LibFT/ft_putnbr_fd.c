/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:53:09 by zali              #+#    #+#             */
/*   Updated: 2025/02/27 12:02:47 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*ptr;

	ptr = ft_itoa(n);
	if (!ptr)
		return ;
	write(fd, ptr, ft_strlen(ptr));
	free(ptr);
}
/*
#include <fcntl.h>
int main(void)
{
	int fd = open("word", O_WRONLY);
	ft_putnbr_fd(-123123123, fd);
}
*/
