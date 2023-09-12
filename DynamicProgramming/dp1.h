#pragma once
#include <iostream>
#include <map>

//재귀호출
//	트리로 표현하면 이해하기 쉽다.
//	시간복잡도 : 전체 노드의 갯수
//	공간복잡도 : 트리의 높이

//BruteForce - 전수조사
// TC : O(2^n)
// SC : O(n)
int64_t Fibonacci(int n)
{
	//base case
	if (n<=2)
	{
		return 1;
	}

	//recursive
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Optimize - 중복계산 제거
//		문제를 풀고 결과를 저장한다음에 재사용
// TC : O(n)
// SC : O(n)
int64_t Fibonacci_memo(int n, std::map<int, int64_t>& memo)
{
	if (memo.count(n) == 1)
	{
		return memo[n];
	}

	//base case
	if (n <= 2)
	{
		return 1;
	}

	//recursive
	memo[n] = Fibonacci_memo(n - 1,memo) + Fibonacci_memo(n - 2,memo);
	return memo[n];
}


//TC : O(2^(m+n))
//SC : O(m+n)
int FindWay(int m, int n)
{
	//base case
	if (m == 1 && n == 1)
	{
		return 1;
	}
	if (m == 0 || n == 0)
	{
		return 0;
	}

	//recursive case
	return FindWay(m - 1, n) + FindWay(m, n - 1);
}