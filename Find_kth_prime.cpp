#include<bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define ll long long
#define endl '\n'
using namespace std;
const int mxn = 10e7+2;
bitset<mxn> isPrime; 
vector<int>v;

void sieve(int n){
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    v.reserve(5e6);    // avoid reallocation
    v.push_back(2);
    for(int i = 3; i * i<=n ; i += 2){       // avoid even number
        if(isPrime[i]){
           for(int j = i * i; j<=n; j += 2 * i){
           isPrime[j] = 0; 
        }
        }    
    }
    for(int i = 3; i<=n ; i += 2){
        if(isPrime[i] == true) v.push_back(i);
    }
}
// void seg_sieve(int l, int r){
//     int mxn2 = r-l+1;
//     bool isSeg[mxn2];
//     memset(isSeg,1,sizeof(isSeg));
//     if(l == 1) isSeg[0] = false;
//     for(auto u : v){
//         if(u * u > r) break;
//         ll s = max(u * u, (l + u - 1) / u * u);
//           for (ll i = s; i <= r; i += u) {
//             if (i != u) isSeg[i - l] = false;
//         }
//     }
//     for (int i = 0; i < mxn2 ; i++) {
//         if (isSeg[i] == true) cout << l + i << endl;
//     }

// }
int main(){
    fast();
    sieve(mxn);
    int t; cin>>t;
    while(t--){
        int k;   cin>>k;
        cout << v[k-1] << endl;
    }
   return 0;
}




/*input:
7
1
10
100
1000
10000
100000
1000000

output:
2
29
541
7919
104729
1299709
15485863
complexity √nlog(n)*/