#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
#define ll long long

vector<ll> sg;
vector<ll> v;
class s_tree{
    public:
       s_tree(int n){
         sg.resize(4 * n + 1, 0);
         v.resize(n + 1);
       }
       void s_tree_build(int indx, int start, int end, int i){
          if(start == end){
             sg[i] = v[start];
             return;
          }
          int mid = (start + end) / 2;
          s_tree_build(indx, start, mid, 2 * i);
          s_tree_build(indx, mid + 1, end, 2 * i + 1);
          sg[i] = sg[2 * i] + sg[2 * i + 1];
       }

       ll query(int indx, int start, int end, int l, int r, int i){
           if(start > r || end < l) return 0;
           if(start >= l && end <= r) return sg[i];
           int mid = (start + end) / 2;
           ll left_sum = query(indx, start, mid, l, r, 2 * i);
           ll right_sum = query(indx, mid + 1, end, l, r, 2 * i + 1);
           return left_sum + right_sum;
       }
};

int32_t main(){
    fast();

    int n; cin>>n;

    s_tree st(n);
    for(int i = 1; i<=n ; i++)cin>>v[i];

    st.s_tree_build(1, 1, n, 1);
    int q; cin>>q;
    while(q--){
        ll l,r;  cin>>l>>r;
        cout << st.query(1, 1, n, l, r, 1) << endl;
    }

    return 0;

}



// Input
// 8
// 2 3 5 1 10 11 8 9
// 3
// 1 3
// 2 6
// 5 8

// Output
// 10
// 30
// 38