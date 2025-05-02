#include<bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define ppb                 pop_back
#define checkmate           return 0
#define yes                 cout<<"yes"<<endl
#define no                  cout<<"no"<<endl
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/gcd(a,b)
#define for1(i , y)         for(ll i = y ; i<n ; i++) 
#define for2(i , y)         for(ll i = y ; i<m ; i++) 
#define vi(n)               vector<int> v(n)
#define vll                 vector<ll>
#define vcin(v)             for(ll i = 0; i<n ; i++) cin>>v[i] 
#define MOD                 1000000007
#define fs                  first
#define sc                  second
#define all(v)              v.begin(),v.end() 
#define allr(v)             v.rbegin(),v.rend()          
#define setpr(x)            fixed<<setprecision(1)
#define vmax                *max_element(v.begin(),v.end())
#define vmin                *min_element(v.begin(),v.end())
#define fbo                 find_by_order
#define ook                 order_of_key
#define mem(a,b)            memset(a , b , sizeof(a))
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl                '\n'
#define dbg(...)
 
 
//             T   B   L   R    TL  TR   BL  BR
//int dx[10] = { 1 ,-1 , 0 , 0 , -1 , -1 , 1 , 1};
//int dy[10] = { 0 , 0 ,-1 , 1 , -1 ,  1 ,-1 , 1};
//            -------------    ----------------
//              side move       diagonal move
 
 
//using namespace __gnu_pbds;
using namespace std;
 
 
// typedef tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds1;  //asn
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds2;   //dsn
 
// typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds3;  //asndng multiset
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds4;    //dsndng multiset
 
 
 
 
void file(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
 
bool isBalanced(char c1 , char c2){
   return (c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']' || c1 == '<' && c2 == '>');
}
 
bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
 
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
 
ll sum(ll n){
    ll ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
 
// vector<int>adj[200005];
// vector<bool> vis(200005 , false);
// bool check_cycle;
 
// void dfs(int node){
//      vis[node] = true;
//      if(adj[node].size() != 2){
//         check_cycle = false;
//      }
//      for(auto child : adj[node]){
//         if(!vis[child]){
//             dfs(child);
//         }
//      }
// }
 
 
//----------------   Solution Here   ----------------/
 
const int mxn = 1005; 
char c[mxn][mxn];
int vis[mxn][mxn];
int dx[] = {1, -1, 0, 0}; 
int dy[] = {0, 0, 1, -1};
int n, m; 
 
void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !vis[x1][y1] && c[x1][y1] == '.') {
            dfs(x1, y1);
        }
    }
}
 
void solve() {
    cin >> n >> m; 
    memset(vis, 0, sizeof(vis)); 
    int rooms = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (c[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                rooms++;
            }
        }
    }
 
    cout << rooms << endl;
}
int main()
{
    fast();
    solve();
 
    //file();
    /*ll t ; cin>>t;
    //int tt=1;
    while(t--) 
    {
      //cout<<"Case "<<tt<<": ";
      //tt++;
      solve();
    }*/
   checkmate;
}
