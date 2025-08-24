#include<bits/stdc++.h>
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl  '\n'
using namespace std;
const int mxn = 2e5 + 123;
vector<ll>v,sg;
class s_tree{
    public: 
       s_tree(int n){
         sg.resize(4*n+1,0);
        v.resize(n + 1);
       }

       void s_tree_build(int indx, int start, int end){
            if(start == end){
                sg[indx] = v[start];
                return;
            }
            int mid = (start + end) / 2;
            s_tree_build(indx * 2 , start, mid);
            s_tree_build(indx * 2 + 1, mid + 1, end);
            sg[indx] = sg[indx * 2] + sg[indx * 2 + 1];
       }   
       void printtree(){
            for(int i = 1; i<=15; i++){
                cout << sg[i] << " ";
            }
            cout << endl;
       } 
};

int main(){
    fast();

    int n; cin>>n;
    s_tree st(n);

    for(int i = 1; i<=n ; i++) cin>>v[i];

    st.s_tree_build(1,1,n);
    st.printtree();
}



// Input
// 8
// 2 3 5 1 10 11 8 9

// Output
// 49 11 38 5 6 21 17 2 3 5 1 10 11 8 9 