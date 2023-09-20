#include <iostream>
#include <vector>
#include "dp1.h"
#include "dp2.h"
#include "dp3.h"

std::ostream& operator << (std::ostream& os, std::vector<int>* v)
{
	if (v == nullptr)
	{
		std::cout << "nullptr";
	}
	else
	{
		std::cout << "{";
		for (int i = 0; i < v->size(); i++)
		{
			std::cout << (*v)[i];

			if (i < v->size() - 1)
			{
				std::cout << ",";
			}
		}
		std::cout << "}";
	}
	return os;
}

using string2d = std::list<std::list<std::string>>;
std::ostream& operator << (std::ostream& os, const string2d& v)
{
	std::cout << "{" << std::endl;
	int i{}, j{};

	for (auto e1 : v)
	{
		j = 0;
		std::cout << "    {";
		for (auto e2 : e1)
		{
			std::cout << e2;

			if (j < e1.size() - 1)
			{
				std::cout << ",";
			}
			j++;
		}
		std::cout << "}";

		if (i < v.size() - 1)
		{
			std::cout << ",";
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << "}" << std::endl;

	return os;
}

//void dp1()
//{
//	using namespace dp_base;
//
//	std::map<int, int64_t> memo;
//
//	std::cout << Fibonacci_memo(50, memo) << std::endl;
//
//	std::cout << FindWay(3, 3) << std::endl;
//
//	std::map<std::string, int> memo1;
//	std::cout << FindWay2(25, 25, memo1) << std::endl;
//}
//
//void dp2()
//{
//	using namespace  memoization;
//
//	std::vector<int> numbers1 = { 2,3,5 };
//	int sum1 = 8;
//
//	std::vector<int> numbers2 = { 8,6 };
//	int sum2 = 7;
//
//	std::cout << std::boolalpha;
//	std::cout << CanAccumulate(numbers1, sum1) << std::endl;	
//
//	std::cout << std::boolalpha;
//	std::cout << CanAccumulate(numbers2, sum2) << std::endl;
//
//	std::map<int, bool> memo;
//	std::cout << CanAccumulate(numbers1, sum1,memo) << std::endl;
//	memo.clear(); // 메모는 공유되므로 리셋
//	std::cout << CanAccumulate(numbers2, sum2,memo) << std::endl;
//
//	std::map<int, result>memo2;
//	std::cout << HowAccumulate(numbers1, sum1, memo2).get() << std::endl;
//
//	memo.clear(); 
//	std::cout << HowAccumulate(numbers2, sum2, memo2).get() << std::endl;
//
//	memo.clear();
//	std::cout << OptimizeAccumulate(numbers1, sum1, memo2).get() << std::endl;
//
//	memo.clear();
//	std::cout << OptimizeAccumulate(numbers2, sum2, memo2).get() << std::endl;
//	std::vector<std::string> strings = { "ab","abc","cd","def","abcd" };
//	auto target = "abcdef";
//
//	std::cout << std::boolalpha;
//	std::cout << CanGenerate(strings, target) << std::endl;
//
//	std::map<std::string, bool> memo3;
//	std::cout << CanGenerate(strings,target,memo3) << std::endl;
//
//	std::cout << HowManyGenerate(strings, target) << std::endl;
//
//	std::map<std::string, int> memo4;
//	std::cout << HowManyGenerate(strings, target, memo4) << std::endl;
//
//	std::cout << AllCombination(strings, target) << std::endl;
//
//	std::vector<std::string> strings2 = { "ab","abc", "cd", "def","abcd","c","ef" };
//	auto target2 = "abcdef";
//
//	std::cout << AllCombination(strings2, target2) << std::endl;
//}

int main()
{
	using namespace tabulation;
	std::cout << Fibonacci(50) << std::endl;	

	std::cout << FindWays(20, 20) << std::endl;

	std::cout << std::boolalpha;
	std::cout << CanAccumulate({ 2,3,5 }, 8) << std::endl;
	std::cout << HowAccumulate({ 2,3,5 }, 8).get() << std::endl;
	std::cout << OptimizeAccumulate({ 2,3,5 }, 8).get() << std::endl;

	std::cout << CanGenerate({ "ab","abc","cd","def","abcd" }, "abcdef") << std::endl;
	std::cout << CanGenerate({ "bb","ccc"}, "abcdef") << std::endl;
	std::cout << CanGenerate({ "bb","ccc" }, "") << std::endl;

	std::cout << HowManyGenerate({ "ab","abc","cd","def","abcd","c","d","ef"}, "abcdef") << std::endl;
	std::cout << HowManyGenerate({ "bb","ccc" }, "abcdef") << std::endl;
	std::cout << HowManyGenerate({ "bb","ccc" }, "") << std::endl;

	std::cout << AllGenerate({ "ab","abc", "cd","def","abcd","c","d","ef" }, "abcdef") << std::endl;
}