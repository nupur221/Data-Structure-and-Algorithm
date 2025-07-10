#include<bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define ll long long
#define endl '\n'
using namespace std;
const int mxn = 1e5+12;
bool isPrime[mxn];
vector<int>v;

void sieve(int n){
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i<=n ; i++){
        if(isPrime[i] == true){
           for(int j = i * i; j<=n; j += i){
           isPrime[j] = false; 
        }
        }    
    }
    for(int i = 2; i<=n; i++){
        if(isPrime[i] == true) v.push_back(i);
    }
}
void seg_sieve(int l, int r){
    int mxn2 = r-l+1;
    bool isSeg[mxn2];
    memset(isSeg,1,sizeof(isSeg));
    if(l == 1) isSeg[0] = false;
    for(auto u : v){
        if(u * u > r) break;
        ll s = max(u * u, (l + u - 1) / u * u);
          for (ll i = s; i <= r; i += u) {
            if (i != u) isSeg[i - l] = false;
        }
    }
    for (int i = 0; i < mxn2 ; i++) {
        if (isSeg[i] == true) cout << l + i << endl;
    }

}
int main(){
    fast();
    sieve(1e5);
    int t; cin>>t;
    while(t--){
        int l,r;   cin>>l>>r;
        seg_sieve(l,r);
        cout << endl;
    }
}

