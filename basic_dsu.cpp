#include<bits/stdc++.h>
using namespace std;
const int mxn = 100;
int par[mxn];


void init(){
    for(int i = 1; i<=8 ; i++){
        par[i] = i;
    }
}
bool flag = false;
int find(int u){
    if(flag == true){
        cout << "Called with " << u << endl;
    }
    if(u == par[u]) return u;
    //return find(par[u]);    unoptimized .   complexity n*n
    return par[u] = find(par[u]);   // path compression  O(1) for each query
}
void Union(int u, int v){
        par[v] = u;  //merge
}

int main(){
    int n,m;    cin>>n>>m;
    for(int i = 1; i<= n; i++) par[i] = i;
    while(m--){
        int u,v;   cin>>u>>v;
        int p = find(u);
        int q = find(v);
        if(p != q){
            Union(p,q);
        }
    }
    for(int i = 1; i<=n ; i++) if(par[i] == i) cout << i << endl;
    return 0;
}