#include <iostream>
#include "dp1.h"
#include "dp2.h"
#include "dp3.h"

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
//	std::cout << CanAccumulate2(numbers1, sum1,memo) << std::endl;
//	memo.clear(); // 메모는 공유되므로 리셋
//	std::cout << CanAccumulate2(numbers2, sum2,memo) << std::endl;
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
}