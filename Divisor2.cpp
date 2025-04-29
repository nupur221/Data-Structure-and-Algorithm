//*************  Divisors of every n element  ***************//

#include<bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const int N = (int) 1e6+5;
using namespace std;
vector <int> divisors[123];

int main()
{
  fast();
  int n; cin>>n;
  for( int i = 1; i<=n ; i++){
    int sq = sqrt(i);
    for(int j = 1; j<=sq ; j++){
       if(i % j == 0){
        divisors[i].push_back(j);
        if(i / j != j ) divisors[i].push_back(i/j);
       }
    }
    sort(divisors[i].begin(),divisors[i].end());
  }
  for( int i = 1; i<=n ; i++){
     cout<< i << " : ";
     for(auto u : divisors[i]) cout<< u << " ";
     cout<< endl;
  }

  return 0;
}