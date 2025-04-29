#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

#define N 10000
vector<int> adj[N]; 
int vis[N];        
int dist[N];       

void dfs(int node, int d) {
    vis[node] = 1;      
    dist[node] = d;      

    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, d + 1); 
        }
    }
}

int main() {
    fast();
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cin >> source;
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    dfs(source, 0); 
    for (int i = 1; i <= n; i++) {
        cout << "From Source " << source << " to distance of node " << i << " = " << dist[i] << endl;
    }

    return 0;
}
