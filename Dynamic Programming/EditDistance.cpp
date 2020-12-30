#include <bits/stdc++.h>

using namespace std;


//Edit distance:- https://practice.geeksforgeeks.org/problems/edit-distance3702/1
//Time:- O(m*n)
//Space:- O(m*n) Can be done in linear space.
int editDistance(string s, string t)
{
	int m = s.length();
	int n = t.length();
	int dp[m + 1][n + 1];
	for (int i = 0; i <= m; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i <= n; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else
			{
				dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
			}
		}
	}

	return dp[m][n];
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
		string s, t;
		cin >> s >> t;
		cout << editDistance(s, t) << endl;
	}
	return 0;
}