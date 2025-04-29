//Cycle detection and count for undirected graph

#include<bits/stdc++.h>
using namespace std;
#define N 10000
vector<int> adj[N];
bool vis[N];
int cnt = 0;
int ans = 0;
bool dfs (int node, int par)
{
    vis[node] = true;
    for(auto child : adj[node]){
        if(vis[child] == 0){
            if(dfs(child,node)) return true;
        }
        /*else {
            if(child != par) return true;
        }*/
        else if (child != par) {
            cnt++;
        }
        
    }
    return false;
}
int main(){
     int n,m; cin>>n>>m;
     while(m--){
        int u,v;   cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
           ans = dfs(i, -1);
        }
    }
    /*if(ans == true) cout << "Found Cycle "<< endl;
    else cout << "Not Cycle" << endl;*/

    int totalCycles = cnt / 2; 
    if (totalCycles > 0) {
        cout << "Found " << totalCycles << " cycle(s) in the graph" << endl;
    } else {
        cout << "No cycle found" << endl;
    }
    return 0;
}

// input :
// 9 11
// 1 2
// 1 3
// 2 5
// 2 4
// 3 4
// 4 7
// 4 6
// 7 8
// 6 8
// 6 9
// 3 9
// output:
// Found 3 cycle(s) in the graph












//Cycle detection and count for directed graph

// #include <bits/stdc++.h>
// using namespace std;

// #define N 10000
// vector<int> adj[N];
// bool vis[N];
// bool track[N];
// int cycleCount = 0;

// bool dfs(int node) {
//     vis[node] = true;
//     track[node] = true;

//     for (int neighbor : adj[node]) {
//         if (!vis[neighbor]) {
//             if (dfs(neighbor)) {
//                 return true;
//             }
//         } else if (track[neighbor]) {
//             cycleCount++;
//             return true;
//         }
//     }

//     track[node] = false;  // Remove node from recursion stack before returning
//     return false;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }
//     for (int i = 1; i <= n; i++) {
//         if (!vis[i]) {
//             dfs(i);
//         }
//     }
//     cout << "Total cycles found: " << cycleCount << endl;
//     return 0;
// }


// input :
// 6 7
// 1 2
// 2 4
// 4 3
// 3 1
// 2 5
// 5 6
// 6 2

// output :
// Total cycles found: 2
