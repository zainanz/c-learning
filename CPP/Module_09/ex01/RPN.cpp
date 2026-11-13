#include "RPN.hpp"
static bool	isoperator(char c)
{
	return (c == '*' || c == '+' || c == '-' || c == '/');
}

static int	process_data(std::stack<double>& data, char op)
{
	if (data.size() < 2)  return 1;
	double second = data.top();
	data.pop();
	double first = data.top();
	data.pop();
	if (op == '+') data.push(first + second);
	if (op == '*') data.push(first * second);
	if (op == '-') data.push(first - second);
	if (op == '/') data.push(first / second);
	return 0;
}

void	RPN::run(std::string rawstr){
	std::stack<double>	sdata;

	for (unsigned int i = 0; i < rawstr.size(); i++)
	{
		if (isspace(rawstr[i])) continue ;
		if (i + 1 < rawstr.size() && isdigit(rawstr[i]) && isdigit(rawstr[i+1])){
			std::cerr << "error: valid values < 10;" << std::endl;
			return ;
		}
		if (isdigit(rawstr[i])) sdata.push(rawstr[i] - '0');
		else if (isoperator(rawstr[i])){
			if (process_data(sdata, rawstr[i])){
				std::cerr << "Error: invalid input" << std::endl;
				return ;
			}
		}
		else {
			std::cerr << "error: invalid character " << rawstr[i] << std::endl;
			return ;
		}
	}
	if (sdata.size() != 1)
		std::cerr << "error: invalid input" << std::endl;
	else
		std::cout << sdata.top() << std::endl;
	return ;
}

