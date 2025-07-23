#include <bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

const int m = 1000000007;
const int msz = 1e6 + 2;
ll fact[msz];
ll invFact[msz];

ll power(ll base , ll pw , ll mod){
    int res = 1;
    while(pw){
        if(pw % 2 == 1){
            res = (res * base) % mod;
            pw--;
        }
        else{
            base = (base * base) % mod;
            pw /= 2;
        }
    }
    return res % mod;
}
void factorialCalc(int n){
    fact[0] = 1;
    for(int i = 1; i<=n ; i++){
        fact[i] = (i * fact[i - 1]) % m;
    
    }
    // for division
    invFact[n] = power(fact[n] , m - 2, m);
     for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % m;
    }
}
ll ans(int a, int b){
    if(b < 0 || b > a) return 0;
    return fact[a] % m * invFact[b] % m * invFact[a - b] % m;
}


int main() {
    fast();
    factorialCalc(msz);
    int n; cin>>n;
    while(n--){
        int a,b;  cin>>a>>b;
        cout << ans(a,b) << endl;
    } 
    return 0;
}

// CSES
