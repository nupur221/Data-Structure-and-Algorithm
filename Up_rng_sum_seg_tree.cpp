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

       void update(int indx, int start, int end, int pos, int val, int i){
           if(start == end){
             sg[i] = val;
             v[pos] = val;
            return;
           }
           int mid = (start + end) / 2;
           if(pos <= mid) update(indx, start, mid, pos, val, 2 * i);
           else update(indx, mid + 1, end, pos, val, 2 * i + 1);
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
        ll l,r, pos, val;  cin >> l >> r >> pos >> val;
        cout << "Sum before update :" << st.query(1, 1, n, l, r, 1) << endl;
        st.update(1, 1, n, pos, val, 1);
        cout << "Sum after update :" << st.query(1, 1, n, l, r, 1) << endl;

    }

    return 0;

}





// Input
// 5
// 1 2 3 4 5
// 1
// 1 5 3 10           1 theke 5 index er moddhe 3 tomo index e 10 update kore then total array sum koro

// output
// Sum before update :15
// Sum after update :22