#include <bits/stdc++.h>

using namespace std;


//Longest common subsequence:- https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
//Time:- O(N*M)
//Space:- O(N*M) can be optimised to linear.

int dp[105][105];

int lcsRecur(string s1, string s2, int i, int j)
{
	if (i > s1.length() || j > s2.length()) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	if (s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + lcsRecur(s1, s2, i + 1, j + 1);

	return dp[i][j] = max(lcsRecur(s1, s2, i, j + 1), lcsRecur(s1, s2, i + 1, j));
}

int lcs(string s1, string s2) {
	memset(dp, -1, sizeof(dp));
	return lcsRecur(s1, s2, 1, 1);

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
		int x, y;
		cin >> x >> y;
		string s1, s2;
		cin >> s1 >> s2;
		cout << lcs(s1, s2) << endl;
	}
	return 0;
}