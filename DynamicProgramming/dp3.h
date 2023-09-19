#pragma once
#include <iostream>
#include <vector>

//tabulation(���̺�ȭ)
//	1. ǥ�� ���簡
//		- memoization 1,2,�ܰ踦 ����
//		a. ���� n�� ���� [n+1]ũ���� �迭�� ����
//		b. �迭�� �ʱ�ȭ �մϴ�. (������ �⺻��)
//		c. base case�� ä��ϴ�.
//		d. traverse : �迭�� ��ȸ�ϸ鼭 ��Ȳ�� ����
//	2. �׽�Ʈ
//		�񱳴���� �����Ƿ� �׽�Ʈ�� �� ���� �ؾ��Ѵ�.

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
	// 0�� j��, i�� 0�� = 0
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
