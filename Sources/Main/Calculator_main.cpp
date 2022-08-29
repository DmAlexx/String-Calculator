#include "Calculator.hpp"
#include "string"

int main()
{
	std::string str = "3*4*5-12+7*3-15/3";

	//std::cout << "Enter expression less than 20 symbols or press '0' to exit :" << std::endl;
	//while (true)
	//{
	//	std::cin >> str;
	//	if (str.size() < 20 && str != "0")
	//	{
	//		Calculator calc;
	//		//calc.calc(str);
	//	}
	//	if (str == "0")
	//	{
	//		break;
	//	}
	//}
	Calculator calc;
	std::cout << calc.calc(str);
	return 0;
}