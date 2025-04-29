#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (fibo (n-1) + fibo (n-2));
}
int main(){
    for(int i = 0; i<1000 ; i++) dp[i] = -1;
    fibo(5);

    
    return 0;

}