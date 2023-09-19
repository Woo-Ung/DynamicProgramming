// Dynamic Programming ����

#pragma once
#include <iostream>
#include <map>
#include <string>


namespace dp_base
{
	//���ȣ��
	//	Ʈ���� ǥ���ϸ� �����ϱ� ����.
	//	�ð����⵵ : ��ü ����� ����
	//	�������⵵ : Ʈ���� ����

	//BruteForce - ��������
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

	// Optimize - �ߺ���� ����
	//		������ Ǯ�� ����� �����Ѵ����� ����
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


	//DynamicProgramming (������ȹ��)
	//	memoization(�޸�ȭ)
	//		������ ���� �޸� ������� ��Ȱ��
	//		
	//	1. ������ Ǭ�� - BruteForce
	//		a. ������ tree ������ ǥ���� ����.
	//		b. ���ȣ��� ����
	//
	//	2. Memoization
	//		a. ����� ������ ã�´�.
	//		b. �����ϰ� ���� - �޸�
	//
	//	3. �׽�Ʈ
	//		a. 1,2 �� ����� ���ƾ� �Ѵ�.
	//		b. 1���� TestCase(�Է�/��� ����)�� 2���� ����

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