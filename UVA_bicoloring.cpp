#include <bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define endl '\n'
using namespace std;

const int mx = 200; 
vector<int> adj[mx]; 
int col[mx];      

bool dfs(int node, int c) {
    col[node] = c; 
    for (auto child : adj[node]) {
        if (col[child] == -1) {
            if (!dfs(child, 1 - c)) return false;
        } else if (col[child] == col[node]) return false;
    }
    return true;
}

int main() {
    while (true) {
        int n; 
        cin >> n;
        if (n == 0) break;
        int m; cin >> m;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        memset(col, -1, sizeof(col));

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool isBipartite = true;
        if (!dfs(0, 0)) {
            isBipartite = false;
        }   
        if (isBipartite) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }

    return 0;
}