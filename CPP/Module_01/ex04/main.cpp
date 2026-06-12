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

std::string	filter(std::string &str, std::string fstr, std::string s2)
{
	std::string replaced_string;
	size_t      idx = 0; 
	size_t      prev_idx = 0;

	while (idx != std::string::npos)
	{
		idx = str.find(fstr, prev_idx);
        if (idx != std::string::npos){
            replaced_string += str.substr(prev_idx, idx - prev_idx);
            replaced_string += s2;
            prev_idx = idx + fstr.length();
        }
        else{
            replaced_string += str.substr(prev_idx, str.length());
        }
	}
    return (replaced_string);
}

int	main(int argc, char *argv[])
{
	std::string buffer;
	std::string output;
	if (argc != 4)
	{
		std::cerr << "[ERROR] Invalid Arguments." << std::endl;
		std::cerr << "[ERROR] ./filter <filename> <str1> <str2>" << std::endl;
		return (1);
	}
    if (argv[2][0] == '\0'){
        std::cerr << "[ERROR] no previous regular expression" << std::endl;
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
	std::string ofname = std::string(argv[1]) + std::string(".replace");
	outfile.open(ofname.c_str(), std::ios::out);
	outfile << output;
	infile.close();
	return (0);
}
