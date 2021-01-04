#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    vector<int> BFSlist;
    queue<int> q;
    q.push(0);
    int vis[N] = {0};
    BFSlist.push_back(0);
    vis[0] = 1;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto child:g[curr])
        {
            if(!vis[child])
            {
                q.push(child);
                BFSlist.push_back(child);
                vis[child] = 1;

            }
        }
    }
    return BFSlist;
}