#include "Calculator.hpp"
#include "string"

int main()
{
	std::string str;

	std::cout << "Enter expression less than 20 symbols or press '0' to exit :" << std::endl;
	while (true)
	{
		std::cin >> str;
		if (str.size() < 20 && str != "0")
		{
			Calculator calc;
			std::cout << " = " << calc.calc(str) << std::endl;
			std::cout << "Enter expression less than 20 symbols or press '0' to exit :" << std::endl;
		}
		if (str == "0")
		{
			break;
		}
	}
	
	return 0;
}