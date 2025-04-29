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
    int n;  cin>>n;
    vector<int>v(n),sum(n);
    for(int i = 0; i<n ; i++) cin>>v[i];
    sum[0] = v[0];
    for(int i = 1; i<=n ; i++){
        sum[i] = sum[i-1]+v[i];
    }
    for(auto u : sum) cout<< u << " ";
    cout<<endl;
   
   checkmate;
}











