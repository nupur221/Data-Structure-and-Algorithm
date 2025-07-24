
//     Catalan Number     //


#include <bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

const int m = 1000000007;
const int msz = 2e6 + 2;
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
    invFact[n] = power(fact[n] , m - 2, m);
     for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % m;
    }
}
ll nCr(int n, int r){
    if(r < 0 || r > n) return 0;
    return fact[n] % m * invFact[r] % m * invFact[n - r] % m;
}

ll catalan(int k) {
    ll ans = nCr(2 * k, k);
    ans  = ans * power(k + 1, m - 2, m) % m;
    return ans;
}

int main() {
    fast();
    int n; cin>>n;
    if(n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    int k = n / 2;
    factorialCalc(2 * k);
    cout << catalan(k) << endl;
    return 0;
}
