/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:01:15 by zali              #+#    #+#             */
/*   Updated: 2025/02/17 07:29:47 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *destination, const char *source)
{
	char	*start;

	start = destination;
	while (*destination)
		destination++;
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (start);
}
