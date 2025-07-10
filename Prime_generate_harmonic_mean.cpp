#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e6+123;
bool isPrime[mxn];
vector<int>v;

void primeGen(int n){
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = false;
    for(int i = 2; i<=n ; i++){
        for(int j = i * i; j<=n; j+=i){
           isPrime[j] = false; 
        }
    }
    for(int i = 2; i<=n; i++){
        if(isPrime[i] == 1) v.push_back(i);
    }
}
int main(){
    int n; cin>>n;
    primeGen(n);
    for(auto u : v) cout << u << " ";
    cout << endl;

}

//  complexity :  nln(n);  its not optimized