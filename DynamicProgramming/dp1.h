// Dynamic Programming 개념

#pragma once
#include <iostream>
#include <map>
#include <string>


namespace dp_base
{
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
		if (n <= 2)
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
		memo[n] = Fibonacci_memo(n - 1, memo) + Fibonacci_memo(n - 2, memo);
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


	//DynamicProgramming (동적계획법)
	//	memoization(메모화)
	//		문제의 답을 메모에 적어놓고 재활용
	//		
	//	1. 문제를 푼다 - BruteForce
	//		a. 문제를 tree 구조로 표현해 본다.
	//		b. 재귀호출로 구현
	//
	//	2. Memoization
	//		a. 공통된 패턴을 찾는다.
	//		b. 저장하고 재사용 - 메모
	//
	//	3. 테스트
	//		a. 1,2 의 경과가 같아야 한다.
	//		b. 1번의 TestCase(입력/출력 예제)를 2번에 적용

	// TC : O(n) / O(m*n)
	// SC : O(m+n)
	int FindWay2(int m, int n, std::map<std::string, int>& memo)
	{
		std::string key = std::to_string(m) + "," + std::to_string(n);
		if (memo.count(key) == 1)
		{
			return memo[key];
		}

		std::string rkey = std::to_string(n) + "," + std::to_string(m);
		if (memo.count(rkey) == 1)
		{
			return memo[rkey];
		}


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
		memo[key] = FindWay2(m - 1, n, memo) + FindWay2(m, n - 1, memo);
		return memo[key];
	}
}