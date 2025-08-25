#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
#define ll long long
const ll INF = 1e18;
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
          sg[i] = min(sg[2 * i] , sg[2 * i + 1]);
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
           sg[i] = min(sg[2 * i] , sg[2 * i + 1]);
       }

       ll query(int indx, int start, int end, int l, int r, int i){
           if(start > r || end < l) return INF;
           if(start >= l && end <= r) return sg[i];
           int mid = (start + end) / 2;
           ll left_sum = query(indx, start, mid, l, r, 2 * i);
           ll right_sum = query(indx, mid + 1, end, l, r, 2 * i + 1);
           return min(left_sum , right_sum);
       }

};

int32_t main(){
    fast();

    int n,q; cin>>n>>q;

    s_tree st(n);
    for(int i = 1; i<=n ; i++)cin>>v[i];

    st.s_tree_build(1, 1, n, 1);

    while(q--){
        int type;  cin>>type;
        if(type == 1){
            ll k,u;   cin>>k>>u;
            st.update(1, 1, n, k, u, 1);
        }
        else{
            int a,b;  cin>>a>>b;
            cout << st.query(1, 1, n, a, b, 1) << endl;
        }
    }
    return 0;

}
