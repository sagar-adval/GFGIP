#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

vector<int> dfsList;
int vis[100005];


void dfs2(int node, vector<int> g[])
{
    vis[node] = 1;
    dfsList.push_back(node);
    for(auto x:g[node])
    {
        if(!vis[x]) dfs2(x, g);
    }
}


vector <int> dfs(vector<int> g[], int N)
{
    dfsList.clear();
    memset(vis, 0, sizeof(vis));
    dfs2(0, g);
    return dfsList;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;

        vector<int> g[N];


        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends