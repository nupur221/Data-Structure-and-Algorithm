#include<bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define checkmate           return 0;
#define yes                 cout<<"YES"<<endl;
#define no                  cout<<"NO"<<endl;
#define vmax               *max_element(v.begin(),v.end())
#define vmin               *min_element(v.begin(),v.end())
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl                '\n'
using namespace std;
bool isBalanced (char c1 , char c2)
{
    return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
}
int main()
{
    fast();
    ll n ; cin>>n;
    while(n--){
        string s; cin>>s;

        stack <char> st;
        bool done = 1;

        for(auto u : s){
            if(u == '(' || u == '{' || u == '[') st.push(u);
            else if(st.empty()){
                    done = 0;
                    break;
                }
            else if(isBalanced(st.top(),u)){
                st.pop();
            }
            else {
                done = 0;
                break;
            }
            
        }
        if(!st.empty()) done = 0;

        if(done) cout<<"YES" << endl;
        else cout<< "NO" << endl;

    } 
}


// Codeforces H. Balanced Brackets