#pragma once

#include <stack>
#include <iostream>


// it uses deque -> stack is just a wrapper!
class RPN {
	public:
		static void	run(std::string rawstr);
	private:
		RPN(std::string rawstr);
		virtual ~RPN() = 0;
};
