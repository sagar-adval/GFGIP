#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

int vis[10005];
bool dfs(int node, int par, vector<int> g[])
{
    vis[node] = 1;
    for(auto x:g[node])
    {
        if(!vis[x])
        {
            if(dfs(x, node, g)) return true;
        }
        else if(x != par) return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
    memset(vis, 0, sizeof(vis));
    for(int i= 0;i<V;i++)
    {
        if(!vis[i])
        {
            bool isCyclic = dfs(i, -1, g);
            if(isCyclic) return 1;
        }
    }

    return 0;

}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
// } Driver Code Ends

