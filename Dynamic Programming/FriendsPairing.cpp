#include <bits/stdc++.h>

using namespace std;


//Friends pairing problem:- https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
//Time:- O(n)
//Space:- O(1)
int countFriendsPairings(int n)
{
	int MOD = 1e9 + 7;

	if (n == 1) return 1;
	if (n == 2) return 2;

	long long int prev1 = 2, prev2 = 1, curr = 0;

	for (int i = 3; i <= n; i++)
	{
		curr = (prev1 % MOD + (((i - 1) % MOD * prev2 % MOD) % MOD) % MOD) % MOD;
		prev2 = prev1;
		prev1 = curr;
	}

	return curr % MOD;
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
		cout << countFriendsPairings(n) << endl;
	}
	return 0;
}