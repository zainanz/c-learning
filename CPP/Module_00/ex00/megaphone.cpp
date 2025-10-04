/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:00:55 by zali              #+#    #+#             */
/*   Updated: 2025/09/23 13:33:17 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	char_to_up(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
		std::cout.write(&c, 1);
	}
	else
		std::cout.write(&c, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"; 
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j];j++)
			char_to_up(argv[i][j]);
		if (i + 1 != argc)
			std::cout.write(" ", 1);
	}
	std::cout.write("\n", 1);
}