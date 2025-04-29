#include<bits/stdc++.h>
#define endl  '\n'
#define ll long long
using namespace std;
int main(){
     int n;  cin>>n;
     vector <int> v(n);
     for(int i = 0; i<n ; i++) cin>>v[i];
     int target ; cin>>target;
     if( binary_search(v.begin(),v.end(),target)) cout<< "YES" << endl;
     else cout<< "NO" << endl;

     return 0;
}