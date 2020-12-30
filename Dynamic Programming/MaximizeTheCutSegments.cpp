#include <bits/stdc++.h>

using namespace std;


//Maximize the cut segments:- https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
//Time:- O(N)
//Space:- O(N)
int maximizeTheCuts(int n, int x, int y, int z)
{
	int dp[n + 1];

	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		if (dp[i] || !i)
		{
			if (i + x <= n)
			{
				dp[i + x] = max(dp[i] + 1, dp[i + x]);
			}

			if (i + y <= n)
			{
				dp[i + y] = max(dp[i] + 1, dp[i + y]);
			}

			if (i + z <= n)
			{
				dp[i + z] = max(dp[i] + 1, dp[i + z]);
			}
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
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		cout << maximizeTheCuts(n, x, y, z) << endl;
	}
	return 0;
}