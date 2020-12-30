#include <bits/stdc++.h>

using namespace std;


int longestCommonSubstring(string s1, string s2, int n, int m)
{
	int dp[n + 1][m + 1];
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else dp[i][j] = 0;
		}
	}

	return ans;
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
		int n, m;
		cin >> n >> m;
		string s1, s2;
		cin >> s1 >> s2;
		cout << longestCommonSubstring(s1, s2, n, m) << endl;
	}
	return 0;
}