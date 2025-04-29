#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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


//----------------   Solution Here   ----------------/
const int mxn = 50;
char arr[mxn][mxn];
int vis[mxn][mxn];
int cnt = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n;
void dfs(int x, int y) {
    vis[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && arr[x1][y1] != '#' && !vis[x1][y1]) {
            dfs(x1, y1);
        }
    }
}

int main() {
    fast();
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> m >> n;
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < m; j++) {  
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(x, y);
        cout << "Case " << i << ": " << cnt << endl;
    }
    checkmate;
}