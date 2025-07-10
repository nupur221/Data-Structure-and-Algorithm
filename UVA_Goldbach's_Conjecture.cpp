#include<bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define endl '\n'
using namespace std;
const int mxn = 1e6+123;
bool isPrime[mxn];
vector<int>v;

void primeGen(int n){
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = false;
    for(int i = 2; i<=n ; i++){
        if(isPrime[i] == true){
           for(int j = i + i; j<=n; j+=i){
           isPrime[j] = false; 
        }
        }    
    }
    isPrime[2] = false;
    for(int i = 3; i<=n; i++){
        if(isPrime[i] == 1) v.push_back(i);
    }
}
int main(){
    fast();
    primeGen(1e6);
    int n; 
    while(cin >> n){
        if(n == 0) break;
        int diff = -1, p1 = -1, p2 = -1;
        for(auto u : v){
            if(u > n) break;
            int temp1 = u, temp2 = n - u;
            if(temp2 > 2 && isPrime[temp2] == 1){
                diff = abs(temp1 - temp2);
                p1 = temp1;
                p2 = temp2;
                
            }
        }
        if(p1 == -1) cout<< "Goldbach's conjecture is wrong." << endl;
        else cout << n << " = " << p2 << " + " << p1  << endl;
    }
 return 0;
}