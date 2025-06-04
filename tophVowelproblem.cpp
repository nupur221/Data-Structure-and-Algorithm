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
const int N = 1e5;
using namespace std;

bool isVowle(char c){
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void solve(){

       string s;
       cin.ignore();
       getline(cin, s);
       reverse(s.begin(),s.end());
       for(int i = 0; i<s.size(); i++){
          if(s[i] == ' ') continue;
          if(isVowle(s[i])) continue; 
           if(s[i] == 'b') s[i] = 'z';
           else{
               s[i] = s[i] - 1 ;
               if(isVowle(s[i])){
                s[i] = s[i] - 1;
               } 
        }   
   }
    cout<< s <<endl; 
}
int main()
{
    fast();
    ll t ; cin>>t;
    while(t--)  solve();
   checkmate;
}