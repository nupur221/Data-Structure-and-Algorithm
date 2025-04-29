#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define endl '\n'
using namespace std;
const int mx = 1e4+12;
vector<int> adj[mx];
bool vis[mx];
int dist[mx];

void bfs(int source){
    queue<int> q;
    vis[source] = 1;
    dist[source] = 0;
    q.push(source);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto next : adj[node]){
            if(!vis[next]){
                vis[next] =  1;
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
}
int main() {
    fast();
        //for(int i = 0; i<mx ; i++) adj[i].clear();
        int n,m;   cin>>n>>m;
        while(m--){
            int u,v;   cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int source;   cin>>source;
        bfs(source);
        cout << "From node :" << source << endl;
        for(int i = 1; i<=n ; i++){
            cout << "Distance of " << i << " is : " << dist[i] << endl;
        }
    return 0;
}