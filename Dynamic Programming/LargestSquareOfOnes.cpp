#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        int dp[n][m];

        memset(dp, 0, sizeof(dp));

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    dp[i][j] = 1;
                    if (i && j)
                    {
                        dp[i][j] += min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }
                }

                ans = max(ans, dp[i][j]);
            }
        }


        cout<<ans<<endl;
    }
    return 0;
}