//***********Unsolved**********//

#include<bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define ppb                 pop_back
#define checkmate           return 0
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define for1(i , y)         for(ll i = y ; i<n ; i++) 
#define for2(i , y)         for(ll i = y ; i<m ; i++)             
#define setpr               cout<<fixed<<setprecision(1)<< x <<endl
#define vmax               *max_element(v.begin(),v.end())
#define vmin               *min_element(v.begin(),v.end())
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl                '\n'
const int N = 1e9 + 7;
using namespace std;

ll Inversion_cnt(vector<int> v , int n){
   ll result = 0 , one_cnt = 0;
    for1(i , 0){
      if(v[i] == 1) one_cnt++;
      else result += one_cnt;

      return result;
    }
}
int solve(){
   int n;   cin>>n;
   
   vector<int> v(n);
   for1(i , 0) cin>>v[i];

   ll ans = Inversion_cnt(v,n);         // 1st inversion count of an array
   int zero = -1;
   for1(i , 0){
      if(v[i] == 0){
         v[i] = 1;
         zero = i;
         break;
      }
   }
   ans = max(ans,Inversion_cnt(v,n));    // step 2

   if(zero != -1){       
      v[zero] = 0;
   }

   for(int i = n-1; i>=0 ; i--){
       if(v[i] == 1){
         v[i] = 0;
         break;
       }
   }
   
   ans = max(ans,Inversion_cnt(v,n));     // step 3

   cout << ans << endl; 
      
}
int main()
{
    fast();

   ll t ; cin>>t;
    //int tt=1;
    while(t--) 
    {
      //cout<<"Case "<<tt<<": ";
     // tt++;
     solve();
    }

   // solve();
   checkmate;
}