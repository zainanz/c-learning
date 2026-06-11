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
#include <string>

int is_same(char *fstr, char *s2){
	while (*s2){
		if (*fstr != *s2) return 0;
		s2++;
		fstr++;
	}
	return 1;
}
		/*	
			for (unsigned int j = 0; j < fstr_len; j++)
			{
				if (str[i + j] != fstr[j])
					continue ;
				if (j == fstr.length() - 1)
				{
					replaced_string += s2;
					i+= j + 1;
				}
			}
		*/

std::string	filter(std::string &str, std::string fstr, std::string s2)
{
	std::string	replaced_string;
	unsigned int str_len = str.length();
	//unsigned int fstr_len = fstr.length();

	int idx = 0; 
	int prev_idx = 0;
	while (idx != -1)
	{
		idx = str.find(fstr, idx);
		if (idx != -1){
			replaced_string += str.substr(prev_idx, idx);
			replaced_string += s2;
			prev_idx = idx;
		}
		else
		{
			replaced_string += str.substr(prev_idx, str_len);
		}
		printf("%d", idx);
	return replaced_string;
	}
	return (replaced_string);
}

int	main(int argc, char *argv[])
{
	std::string buffer;
	std::string output;
	if (argc != 4)
	{
		std::cerr << "[ERROR] Invalid Arguments.\n";
		std::cerr << "[ERROR] ./filter <filename> <str1> <str2>\n";
		return (1);
	}
	std::fstream infile(argv[1], std::ios::in);
	std::fstream outfile;
	if (!infile.is_open()){
		std::cerr << "[ERROR] Invalid filename" << std::endl;
		return 1;
	}
	while (std::getline(infile, buffer, '\0')){
		output += filter(buffer, argv[2], argv[3]);
	}
	std::cout << output << std::endl;
	std::string ofname = std::string(argv[1]) + std::string(".replace");
	outfile.open(ofname.c_str(), std::ios::out);
	outfile << output;
	infile.close();
	return (0);
}
