#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;  cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<ll> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        stack<int> s;
        ll mx_area = 0;
        vector<ll> l_bar(n), r_bar(n);
        for(int i = 0; i<n ; i++){
            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            }
            if(s.empty()) l_bar[i] = -1;
            else l_bar[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i>=0 ; i--){
            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            }
            if(s.empty()) r_bar[i] = n;
            else r_bar[i] = s.top();
            s.push(i);
        }
        for(int i = 0; i<n ; i++){
            ll area = h[i] * (r_bar[i] - l_bar[i] - 1);
            mx_area = max(mx_area,area);
        }

        cout << "Case " << i << ": " << mx_area << endl;
        
    }
    return 0;
}