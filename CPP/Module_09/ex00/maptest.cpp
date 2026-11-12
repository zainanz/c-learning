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
	time_t		utime;
}	dateData;

enum INVALID_DATA {
	INVALID_DATE,
	INVALID_VALUE,
	INCOMPLETE,
	VALID_DATA
};

bool	is_valid_date(std::string date)
{
	// 1234-12-12
	for (size_t i = 0; i < date.size();i++)
	{
	}
	return true;
}

void	remove_space(std::string& s)
{
	std::string newstr;
	int sidx;
	int eidx = s.size() - 1;
	if (s.size() == 1) return ;
	for (unsigned int i = 0; i < s.size();i++)
	{
		if (!isspace(s[i])){
			sidx = i;
			break ;
		}
	}
	for (int i = static_cast<int>(s.size()) - 1; i > 0; i--)
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
	return idx;
}
time_t	get_time_t(std::string timestr)
{
	std::string buff;
	struct tm time_tm;
	memset(&time_tm, 0, sizeof(tm));

	buff = timestr.substr(0, 4);
	time_tm.tm_year = strtol(buff.c_str(), NULL, 10);

	buff = timestr.substr(5, 2);
	time_tm.tm_mon = strtol(buff.c_str(), NULL, 10);

	buff = timestr.substr(8, 2);
	time_tm.tm_mday = strtol(buff.c_str(), NULL, 10);
	return mktime(&time_tm);
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
	while (getline(file, output)){
		if (extract_key_value(output, key, value, ",") == std::string::npos) continue ;
		dd[key].val = strtod(value.c_str(), NULL);
		dd[key].utime = get_time_t(key);
	}
	file.close();
	return 0;
}
enum BUFFER_ERRORS {
	BAD_INPUT,
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
	}
}

std::map<std::string, dateData>::iterator get_closest_lowest(std::string date, std::map<std::string, dateData>& dd){
	std::map<std::string, dateData>::iterator it;
	std::map<std::string, dateData>::iterator min_it = dd.begin();

	time_t curtime = get_time_t(date);
	time_t it_time;
	for (it = dd.begin(); it != dd.end(); it++)
	{
		it_time = it->second.utime;
		if (it_time < curtime && it_time > min_it->second.utime) {
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
	while (getline(file, buffer))
	{
		if (extract_key_value(buffer, date, value, "|") == std::string::npos){
			print_buffer_error(BAD_INPUT, buffer);
			continue ;
		}
		std::map<std::string, dateData>::iterator it = dd.find(date);
		if (it == dd.end()) it = get_closest_lowest(date, dd);
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
