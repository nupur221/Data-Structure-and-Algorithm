#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
#define ll long long
const ll mxn = 2e5 + 123;

class SegmentTree {
private:
    int n;
    vector<ll> prop;
    vector<bool> vis;
    vector<int> v;

    void shift(int i) {
        if (vis[i]) {
            prop[2*i] += prop[i];
            prop[2*i+1] += prop[i];
            vis[2*i] = true;
            vis[2*i+1] = true;
            prop[i] = 0;
            vis[i] = false;
        }
    }

    void build(int i, int start, int end) {
        if (start == end) {
            prop[i] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*i, start, mid);
        build(2*i+1, mid+1, end);
    }

    void update(int i, int start, int end, int l, int r, int val) {
        if (l > end || r < start) return;
        if (l <= start && end <= r) {
            prop[i] += val;
            vis[i] = true;
            return;
        }
        shift(i);
        int mid = (start + end) / 2;
        update(2*i, start, mid, l, r, val);
        update(2*i+1, mid+1, end, l, r, val);
    }

    ll query(int i, int start, int end, int pos) {
        if (start == end) {
            return prop[i];
        }
        shift(i);
        int mid = (start + end) / 2;
        if (pos <= mid) {
            return query(2*i, start, mid, pos);
        } else {
            return query(2*i+1, mid+1, end, pos);
        }
    }

public:
    SegmentTree(int size, vector<int>& arr) {
        n = size;
        v = arr;
        prop.resize(4*n, 0);
        vis.resize(4*n, false);
        build(1, 1, n);
    }

    void rangeUpdate(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    ll pointQuery(int pos) {
        return query(1, 1, n, pos);
    }
};

int32_t main() {
    fast();
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    SegmentTree st(n, v);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            st.rangeUpdate(a, b, u);
        } else {
            int k;
            cin >> k;
            cout << st.pointQuery(k) << endl;
        }
    }
    return 0;
}