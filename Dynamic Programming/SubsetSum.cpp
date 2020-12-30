#include <bits/stdc++.h>

using namespace std;

//Subset sum problem:- https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
//Time:- O(N*sum)
//Space:- O(N*sum)
bool isSubsetSum(int arr[], int N, int sum)
{
	bool dp[N + 1][sum + 1];
	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = true;
	}
	for (int i = 1; i <= sum; i++)
	{
		dp[0][i] = false;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (arr[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			}
		}
	}
	return dp[N][sum];
}

int equalPartition(int N, int arr[])
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	if (sum % 2) return 0;
	return isSubsetSum(arr, N, sum / 2);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		if (equalPartition(n, arr)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}