/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:37:24 by zali              #+#    #+#             */
/*   Updated: 2025/02/16 16:47:37 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int search_str)
{
	int		i;
	char	*addr;

	i = 0;
	addr = 0;
	while (str[i])
	{
		if (str[i] == search_str)
			addr = (char *) &str[i];
		i++;
	}
	return (addr);
}
