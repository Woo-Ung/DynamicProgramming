#include <iostream>
#include "dp1.h"
#include "dp2.h"

std::ostream& operator << (std::ostream& os, std::vector<int>* v)
{
	if (v == nullptr)
	{
		std::cout << "nullptr";
		return os;
	}

	std::cout << "{";
	for (int i=0; i<v->size(); i++)
	{
		std::cout << (*v)[i];
		if (i < v->size() - 1)
		{
			std::cout << ",";
		}
	}
	std::cout << "}";
	return os;
}

int main()
{
	/*std::map<int, int64_t> memo;

	std::cout << Fibonacci_memo(50, memo) << std::endl;*/

	//std::cout << FindWay(3, 3) << std::endl;

	//std::map<std::string, int> memo;
	//std::cout << FindWay2(25, 25, memo) << std::endl;

	std::vector<int> numbers1 = { 2,3,5 };
	int sum1 = 8;

	std::vector<int> numbers2 = { 8,6 };
	int sum2 = 7;

	//std::cout << std::boolalpha;
	//std::cout << CanAccumulate(numbers1, sum1) << std::endl;	

	//std::cout << std::boolalpha;
	//std::cout << CanAccumulate(numbers2, sum2) << std::endl;

	//std::map<int, bool> memo;
	//std::cout << CanAccumulate2(numbers1, sum1,memo) << std::endl;
	//memo.clear(); // 메모는 공유되므로 리셋
	//std::cout << CanAccumulate2(numbers2, sum2,memo) << std::endl;

	std::map<int, result>memo;
	std::cout << HowAccumulate(numbers1, sum1, memo).get() << std::endl;

	memo.clear(); 
	std::cout << HowAccumulate(numbers2, sum2, memo).get() << std::endl;

}