//  Count connecting component...........1
// #include<bits/stdc++.h>
// #define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define endl '\n'
// using namespace std;

// vector<int> adj[100005];
// int vis[100005];
// void dfs(int node){
//     vis[node] = 1;
//     for(auto child : adj[node]){
//         if(!vis[child]){
//             dfs(child);
//         }
//     }
// }
// int main(){
//     fast();
//     int n,m;   cin>>n>>m;
//     while(m--){
//         int u,v;   cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int cnt = 0;
//     for(int i = 1; i<=n ; i++){
//         if(!vis[i]){
//             dfs(i);
//             cnt++;
//         }
//     } 
//     cout << cnt << endl; 
//     return 0;
// }







//    graph er component e maximum koyta node ache............2
// #include<bits/stdc++.h>
// #define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define endl '\n'
// using namespace std;

// vector<int> adj[100005];
// int vis[100005];
// int cnt;
// void dfs(int node){
//     vis[node] = 1;
//     cnt++;
//     for(auto child : adj[node]){
//         if(!vis[child]){
//             dfs(child);
//         }
//     }
// }
// int main(){
//     fast();
//     int n,m;   cin>>n>>m;
//     while(m--){
//         int u,v;   cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int ans = 0;
//     for(int i = 1; i<=n ; i++){
//         if(!vis[i]){
//             cnt = 0;
//             dfs(i);
//             ans = max(ans,cnt);
//         }
//     } 
//     cout << ans << endl; 
// }











//................  count cycle..........


#include<bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

vector<int>adj[200005];
int vis[200005];
bool check_cycle;
int maxcnt;
void dfs(int node){
     vis[node] = 1;
     maxcnt++;
     if(adj[node].size() != 2){
        check_cycle = false;
     }
     for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child);
        }
     }
}
int main(){
    fast();
    int n,m;  cin>>n>>m;
    while(m--){
        int u,v;    cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    int cnt2 = 0;
    int ans = 0;
    for(int i = 1; i<=n ; i++){
        if(!vis[i]){
            maxcnt = 0;
            check_cycle = true;
            dfs(i);
            cnt2++;
            ans = max(ans, maxcnt);
            if(check_cycle) cnt++;
        }
    }
    cout << "Here is " << cnt2 << " Connecting Conponent and " << cnt << " Cycle" << endl;
    cout << "Maximum node of components " << ans << endl;

    return 0;
}




