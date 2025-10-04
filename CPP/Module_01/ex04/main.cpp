/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:06:48 by zali              #+#    #+#             */
/*   Updated: 2025/10/03 19:18:21 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	filter(std::string &str, std::string fstr, std::string s2)
{
	std::string	replaced_string;

	for (int i = 0; i < str.length(); i++)
	{
		if ( str[i] == fstr[0])
		{
			for (int j = 0; j < fstr.length(); j++)
			{
				if (str[i + j] != fstr[j])
					continue ;
				if (j == fstr.length() - 1)
				{
					replaced_string += s2;
					i+= j + 1;
				}
			}
		}
		replaced_string += str[i];
	}
	return (replaced_string);
}

int	main(int argc, char *argv[])
{
	std::string buffer;
	std::string	f_data;

	if (argc != 4)
	{
		std::cerr << "[ERROR] Invalid Arguments.\n";
		std::cerr << "[ERROR] ./filter <filename> <str1> <str2>\n";
		return (EXIT_FAILURE);
	}
	std::ifstream	f(argv[1]);
	while (getline(f, buffer))
		f_data += buffer + "\n";
	f.close();
	std::string	new_str = filter(f_data, argv[2], argv[3]);
	std::string	output_fname = std::string(argv[1]) + ".replace";
	std::ofstream of(output_fname);
	of << new_str;
	of.close();
	return (EXIT_SUCCESS);
}