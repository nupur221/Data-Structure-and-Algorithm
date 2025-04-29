/*#include<bits/stdc++.h>
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define checkmate           return 0
#define endl                '\n'
using namespace std;

double solve(int h, int m) {
   
    double ah = (h % 12) * 30 + m * 0.5;
    double am = m * 6;
    double diff = abs(ah - am);
    return min(360 - diff, diff);
}

int main() {
    fast();
    int h, m;    cin >> h >> m;
    double angle = solve(h, m);
    cout << fixed << setprecision(7) << angle << endl;
    
    checkmate;
}*/



#include<bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define checkmate           return 0
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define vmax               *max_element(v.begin(),v.end())
#define vmin               *min_element(v.begin(),v.end())
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl                '\n'
const int N = (int) 1e6+5;
using namespace std;
int main(){
    fast();
    int n,m; cin>>n>>m;
    vector<string> str;
    for(int i = 0; i<n ; i++){
        for(int j = 0; i<m ; j++){
            cin>>str[i][j];
        }
    }
    for(auto u : str) cout<<u<<endl;
   checkmate;
}