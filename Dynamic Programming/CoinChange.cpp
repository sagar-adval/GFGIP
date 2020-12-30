#include <bits/stdc++.h>

using namespace std;


//Coin change problem:- https://practice.geeksforgeeks.org/problems/coin-change2448/1
//Time:- O(m*n)
//Space:- O(n)
long long int count( int S[], int m, int n )
{
	long long int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j >= S[i]) dp[j] += dp[j - S[i]];
		}
	}

	return dp[n];
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m;
	cin >> m;
	int S[m];
	for (int i = 0; i < m; i++) cin >> S[i];
	int n;
	cin >> n;
	cout << count(S, m, n) << endl;
	return 0;
}