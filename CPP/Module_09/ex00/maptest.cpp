#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>

#define FLT_DIG 6

typedef struct s_dateData {
	float		val;
	size_t		date_int;
}	dateData;

enum INVALID_DATA {
	INVALID_DATE,
	INVALID_VALUE,
	INCOMPLETE,
	VALID_DATA
};

bool isLeapYear(int year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool is_valid_date(int day, int month, int year)
{
	if (year < 1 || year > 9999 || month < 1 || month > 12) return false;
	int daysInMonth[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	if (isLeapYear(year)) daysInMonth[1] = 29;
	return (day >= 1 && day <= daysInMonth[month - 1]);
}

size_t	date_string_to_int(std::string date)
{
	int year = 0;
	int month = 0;
	int day = 0;
	int dashes = 0;
	for (size_t i = 0; i < date.size();i++)
	{
		if (date[i] == '-')
		{
			dashes++;
			if (dashes > 2) throw 0;
			continue ;
		}
		if (!isdigit(date[i])) throw 0;
		if (dashes == 0)  year = (10 * year) + (date[i] - '0');
		else if (dashes == 1) month = (10 * month) + (date[i] - '0');
		else if (dashes == 2) day = (10 * day) + (date[i] - '0');
	}
	if (!is_valid_date(day, month, year)) throw 0;
	return year * 10000 + month * 100 + day;
}

void	remove_space(std::string& s)
{
	std::string newstr;
	int sidx = 0;
	int eidx = s.size() - 1;
	if (s.size() == 1 && s == " ")
	{
		s = "";
		return ;
	}
	for (unsigned int i = 0; i < s.size();i++)
	{
		if (!isspace(s[i])){
			sidx = i;
			break ;
		}
	}
	for (int i = static_cast<int>(s.size()) - 1; i >= 0; i--)
	{
		if (!isspace(s[i])){
			eidx = i;
			break ;
		}
	}
	s = s.substr(sidx, (eidx + 1) - sidx); 
}

size_t	extract_key_value(std::string output, std::string& key, std::string& value, std::string bp)
{
	size_t idx = output.find(bp);
	if (idx == std::string::npos) return idx;
	key = output.substr(0, idx);
	value = output.substr(idx + 1, output.size());
	remove_space(key);
	remove_space(value);
	if (key.empty() || value.empty()){
		std::cerr << "key or value is empty." << "(Key: " << key << ", Value: " << value << ")" << std::endl;
		exit(1);
	}
	return idx;
}

int	load_data(std::map<std::string, dateData>& dd)
{
	std::ifstream file("data.csv", std::ifstream::in); 
	if (!file.is_open()){
		std::cerr << "failed to open: data.csv" << std::endl;
		return 1;
	}
	std::string output;
	std::string	key;
	std::string value;
	getline(file, output);
	size_t tval;
	while (getline(file, output)){
		if (extract_key_value(output, key, value, ",") == std::string::npos) continue ;
		try {
			tval = date_string_to_int(key);
		}catch(...){
			std::cerr << "invalid date -> " << key << std::endl;
			exit(1);
		}
		dd[key].val = strtod(value.c_str(), NULL);
		dd[key].date_int = tval;
	}
	file.close();
	return 0;
}
enum BUFFER_ERRORS {
	BAD_INPUT,
	BAD_DATE,
	LARGE_VAL,
	NEGATIVE_VAL
};

void	print_buffer_error(BUFFER_ERRORS berror, std::string& output)
{
	switch (berror)
	{
		case BAD_INPUT: {
			std::cout << "Error: bad input => " << output << std::endl;
			break ;
		}
		case LARGE_VAL: {
			std::cout << "Error: too large a number." << std::endl;
			break ;
		}
		case NEGATIVE_VAL: {
			std::cout << "Error: not a positive number." << std::endl;
			break ;
		}
		case BAD_DATE:{
			std::cout << "Error: invalid date => " << output << std::endl;
			break ;
		}
	}
}

std::map<std::string, dateData>::iterator get_closest_lowest(size_t curr_dateint, std::map<std::string, dateData>& dd){
	std::map<std::string, dateData>::iterator it;
	std::map<std::string, dateData>::iterator min_it = dd.begin();

	size_t it_time;
	for (it = dd.begin(); it != dd.end(); it++)
	{
		it_time = it->second.date_int;
		if (it_time < curr_dateint && it_time > min_it->second.date_int) {
			min_it = it; 
		}
	}
	return min_it;
}

void	process_file_data(std::string fname, std::map<std::string, dateData>& dd)
{
	std::ifstream file(fname.c_str(), std::ifstream::in);
	if (!file.is_open()){
		std::cerr << "could not open file: " << fname << std::endl;
		return ;
	}
	std::string buffer;
	getline(file, buffer);
	std::string date;
	std::string value;
	float dval;
	size_t curr_dateint;
	while (getline(file, buffer))
	{
		if (extract_key_value(buffer, date, value, "|") == std::string::npos){
			print_buffer_error(BAD_INPUT, buffer);
			continue ;
		}
		try {
			curr_dateint = date_string_to_int(date);
		}catch(...) {
			print_buffer_error(BAD_DATE, buffer);
			continue ;
		}
		std::map<std::string, dateData>::iterator it = dd.find(date);
		if (it == dd.end()) it = get_closest_lowest(curr_dateint, dd);
		dval = strtod(value.c_str(), NULL);
		if (dval > 1000.0) {
			print_buffer_error(LARGE_VAL, buffer);
			continue ;
		}
		if (dval < 0.0) {
			print_buffer_error(NEGATIVE_VAL, buffer);
			continue ;
		}
		dval *= it->second.val;
	
		std::cout << date << " => " << value <<  " = ";
		if (std::fmod(dval, 1.0)  == 0.0 )
			std::cout  << std::fixed <<  std::setprecision(0) << dval << std::endl;
    	else
        	std::cout << std::fixed << std::setprecision(2) << dval << std::endl;
	}
	return ;
}


int	main(int argc, char *argv[])
{
	std::map<std::string, dateData> dd;

	if (argc != 2) {
		std::cerr << "invalid arguments. ./btc [filename]" << std::endl;
		return 1;
	}
	
	if (load_data(dd)) return 1;
	process_file_data(argv[1], dd);
	return 0;
}
