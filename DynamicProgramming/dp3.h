#pragma once
#include <iostream>
#include <vector>

//tabulation(테이블화)
//	1. 표를 만든가
//		- memoization 1,2,단계를 단축
//		a. 문제 n에 대해 [n+1]크기의 배열을 생성
//		b. 배열을 초기화 합니다. (문제의 기본값)
//		c. base case를 채웁니다.
//		d. traverse : 배열을 순회하면서 상황을 전파
//	2. 테스트
//		비교대상이 없으므로 테스트를 잘 많이 해야한다.

namespace tabulation
{
	// tabulation
	// TC : O(n)
	// SC : O(n)
	int64_t Fibonacci(const int n)
	{
		std::vector<int64_t> table(n + 1, 0);

		//base case
		table[0] = 0;
		table[1] = 1;

		// traverse
		for (int i = 0; i <= n;i++)
		{
			table[i + 1] += table[i];
			table[i + 2] += table[i];

		}
		return table[n];
	}	
}


// TC : O(m * n)
// SC : O(m * n)
int FindWays(int m, int n)
{
	std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));

	// base case
	// 0행 j열, i행 0열 = 0
	table[1][1] = 1;

	// traverse
	for (int row = 0; row <= m; ++row)
	{
		for (int col = 0; col <= n; ++col)
		{
			if (row + 1 <= m)
			{
				table[row + 1][col] += table[row][col];
			}
			if (col + 1 <= n)
			{
				table[row][col+1] += table[row][col];
			}
		}
	}





}
