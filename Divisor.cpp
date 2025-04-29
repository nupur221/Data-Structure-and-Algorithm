#include<bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;

int main()
{
  fast();
  int n; cin>>n;
  vector <int> v;
  int sq = sqrt(n);
  for(int i =1; i<= sq ; i++){
     if(n % i == 0){
        v.push_back(i);
        if(n/i != i) v.push_back(n/i);
     }
  }
  sort(v.begin(),v.end());
  for(auto u : v){
      cout<< u << " ";
  } 
  cout << endl;
 // cout << (v[v.size()-1] +  v[v.size()-2]) << endl;

  return 0;
}