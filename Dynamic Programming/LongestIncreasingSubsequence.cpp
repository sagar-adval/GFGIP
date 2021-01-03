#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];

        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}

int longestSubsequence(int n, int arr[])
{
    int dp[n];

    for(int i=0;i<n;i++)
    {
        dp[i] = 1;
    }

    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp, dp+n);
}
