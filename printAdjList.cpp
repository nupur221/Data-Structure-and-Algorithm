//    Print adjacency list for unweighted graph   

/*#include<bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define ppb                 pop_back
#define checkmate           return 0
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/gcd(a,b)
#define for1(i , y)         for(ll i = y ; i<n ; i++) 
#define for2(i , y)         for(ll i = y ; i<m ; i++) 
#define vi                  vector<int>
#define vll                 vector<ll>
#define vcin                for(ll i = 0; i<n ; i++) cin>>v[i]; 
#define MOD                 1000000007
#define srt                 sort(v.begin(),v.end())           
#define setpr               cout<<fixed<<setprecision(1)<< x <<endl
#define vmax                *max_element(v.begin(),v.end())
#define vmin                *min_element(v.begin(),v.end())
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl                '\n'
using namespace std;
const int N = 2e6 + 7;
vector<int> adj[N];

int main(){
    int node, edge;    cin>>node>>edge;
    for(int i = 1; i<=edge ; i++){
        int u,v;   cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i<=node ; i++){
        cout<< "Adjacent list of " << i <<":";
        for(auto u : adj[i]) cout<< u << " ";
        cout<<endl;
    }
   checkmate; 
}*/






//           Print adjacency list for weighted graph using pair method


#include<bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define ppb                 pop_back
#define checkmate           return 0
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/gcd(a,b)
#define for1(i , y)         for(ll i = y ; i<n ; i++) 
#define for2(i , y)         for(ll i = y ; i<m ; i++) 
#define vi                  vector<int>
#define vll                 vector<ll>
#define vcin                for(ll i = 0; i<n ; i++) cin>>v[i]; 
#define MOD                 1000000007
#define srt                 sort(v.begin(),v.end())           
#define setpr               cout<<fixed<<setprecision(1)<< x <<endl
#define vmax                *max_element(v.begin(),v.end())
#define vmin                *min_element(v.begin(),v.end())
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl                '\n'
using namespace std;
const int N = 2e6 + 7;
vector<pair<int,int>> adj[N];

int main(){
    fast();
    int node, edge;    cin>>node>>edge;
    for(int i = 1; i<=edge ; i++){
        int u,v, weight;   cin>>u>>v>>weight;

        adj[u].push_back( {v, weight} );
        adj[v].push_back( {u, weight} );
    }
    for(int i = 1; i<=node ; i++){
        cout<< "Adjacent list of " << i <<":";
        for(auto u : adj[i]) cout<< "Node : " << u.first << " And Cost : " << u.second<<" ";
        cout<<endl;
    }
   checkmate; 
}







