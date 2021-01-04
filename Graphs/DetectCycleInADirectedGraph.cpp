#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{


public:
    int vis[100005], recVis[100005];
    bool dfs(int node, int par, vector<int> g[])
    {
        if(!vis[node])
        {
            vis[node] = 1;
            recVis[node] = 1;
        }
        for(auto x:g[node])
        {
            if(!vis[x])
            {
                if(dfs(x, node, g)) return true;
            }
            else if(recVis[x]) return true;
        }
        recVis[node] = 0;
        return false;
    }

    bool isCyclic(int N, vector<int> adj[])
    {
        memset(vis, 0, sizeof(vis));
        memset(recVis, 0, sizeof(recVis));
        for(int i= 0;i<N;i++)
        {
            if(!vis[i])
            {
                bool isCyclic = dfs(i, -1, adj);
                if(isCyclic) return 1;
            }
        }

        return 0;
    }

};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> adj[n];

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(n, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends