#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>

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

/*
INVALID_DATA is_valid_data(std::string& op)
{
	size_t idx = op.find(",");
	if (idx == std::string::npos) return INCOMPLETE;
	std::string date = op.substr(0, idx);
	std::string value = op.substr(idx + 1, op.size());
	return VALID_DATA;
}
*/
void	remove_space(std::string& s)
{
	std::string newstr;
	int sidx;
	int eidx = s.size() - 1;
	if (s.size() == 1) return ;
	for (unsigned int i = 0; i < s.size();i++)
	{
		if (s[i] != ' '){
			sidx = i;
			break ;
		}
	}
	for (int i = static_cast<int>(s.size()) - 1; i > 0; i--)
	{
		if (s[i] != ' '){
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
int	load_data(std::map<std::string, float>& cmap)
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
		cmap[key] = strtod(value.c_str(), NULL);
	}
	file.close();
	return 0;
}
enum BUFFER_ERRORS {
	BAD_INPUT,
	LARGE_VAL
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
		}
	}
}
void	process_file_data(std::string fname, std::map<std::string, float>& cmap)
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
		std::map<std::string, float>::iterator it = cmap.find(date);
		if (it == cmap.end()) {
			// iterator to find the closest lower value.
			std::cout << "NOT THERE!        => " << buffer << std::endl;
			continue ;
		}
		dval = strtod(value.c_str(), NULL);
		if (dval < 0.0 || dval > 1000.0) {
			print_buffer_error(LARGE_VAL, buffer);
			continue ;
		}
		std::cout << date << " => " << value <<  " = " << dval * (it->second) << std::endl;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	std::map<std::string, float> curmap;

	if (argc != 2) {
		std::cerr << "invalid arguments. ./btc [filename]" << std::endl;
		return 1;
	}
	
	if (load_data(curmap)) return 1;
	process_file_data(argv[1], curmap);
	return 0;
}
