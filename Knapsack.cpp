#include <bits/stdc++.h>

using namespace std;


//Knapsack Problem:- https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//Time:- O(N*W)
//Space:- O(N*W)
int knapSack(int W, int wt[], int val[], int n)
{
	int dp[n + 1][W + 1];

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (!i || !j) dp[i][j] = 0;
			else if (wt[i - 1] <= j)
			{
				dp[i][j] = max(val[i - 1]
				               + dp[i - 1][j - wt[i - 1]],
				               dp[i - 1][j]);

			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][W];
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int W;
	cin >> W;
	int n;
	cin >> n;
	int wt[n], val[n];
	for (int i = 0; i < n; i++) cin >> wt[i];
	for (int i = 0; i < n; i++) cin >> val[i];
	cout << knapSack(W, wt, val, n) << endl;
	return 0;
}