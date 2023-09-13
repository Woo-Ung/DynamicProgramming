#pragma once
#include <iostream>
#include <vector>
#include <map>

//*Decision Problem
//	���� ���� �� �ִ���?
//
//**Combination Problem
//	������ ����� ���� ����
//
//***Optimization Problem
//	���� ª�� �迭��?
//		����� ��츦 ���ؾ���

//BruteForce
// m : sum, n : numbers�� ũ��
// TC : O(n^m)
// SC : O(m)
bool CanAccumulate(const std::vector<int>& numbers, int sum)
{
	//base case
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	//recursive
	for (auto e : numbers)
	{
		if (CanAccumulate(numbers, sum - e))
		{
			return true;
		}
	}
	return false;
}


//Memoization
// m : sum, n : numbers�� ũ��
// TC : O(m*n)
// SC : O(m)
bool CanAccumulate2(const std::vector<int>& numbers, int sum, std::map<int,bool>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	//base case
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	//recursive
	for (auto e : numbers)
	{
		if (CanAccumulate2(numbers, sum - e,memo))
		{
			memo[sum] = true;
			return true;
		}
	}

	memo[sum] = false;
	return false;
}

//Memoization
// TC : O(m * n)
// SC : O(m^2),	
//		O(m) - �Է� ����� ���⵵���� ������ ���
using result = std::shared_ptr<std::vector<int>>;
result HowAccumulate(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	// base case
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>(); // {}
	}
	if (sum < 0)
	{
		return nullptr;
	}

	//recursive case
	for (const auto e : numbers)
	{
		auto r = HowAccumulate(numbers, sum - e, memo);
		if (r != nullptr)
		{
			r->push_back(e);
			memo[sum] = r;
			return memo[sum];
		}
	}
	memo[sum] = nullptr;
	return memo[sum];
}