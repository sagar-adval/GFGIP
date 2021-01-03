#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int eggDrop(int n, int k)
{
    int dp[n+1][k+1];
    for(int i = 1;i<=n;i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(int i =1;i<=k;i++)
    {
        dp[1][i] = i;
    }

    for(int i=2;i<=n;i++)
    {
        for(int j = 2;j<=k;j++)
        {
            dp[i][j] = INT_MAX;
            for(int flr = 1;flr<=j;flr++)
            {
                dp[i][j] = min(dp[i][j], 1+max(dp[i-1][flr-1], dp[i][j-flr]));
            }
        }
    }

    return dp[n][k];
}

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends