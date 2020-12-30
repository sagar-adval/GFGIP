#include <bits/stdc++.h>

using namespace std;


//Painting the Fence:- https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
//Time:- O(N)
//Space:- O(1)
long long countWays(int n, int k) {

	long long int MOD = 1000000007;
	if (n == 0) return 1;
	if (n == 1) return k;

	long long int same = k, diff = k * (k - 1);
	if (n == 2) return same + diff;
	for (int i = 3; i <= n; i++)
	{
		int prevDiff = diff;
		diff = ((same % MOD + diff % MOD) % MOD) * ((k - 1) % MOD) % MOD;
		same = prevDiff;
	}

	return (same + diff) % MOD;
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
		int n, k;
		cin >> n >> k;
		cout << countWays(n, k) << endl;
	}
	return 0;
}