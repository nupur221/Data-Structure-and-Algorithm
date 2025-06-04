#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int>s;
        long long mx_area = 0;
        vector<long long> l_bar(n), r_bar(n);
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
            long long area = h[i] * (r_bar[i] - l_bar[i] - 1);
            mx_area = max(mx_area,area);
        }
        
        return mx_area;
    }
};
int main(){
    Solution sol;
    vector<int>h = {2, 1, 5, 6, 2, 3};
    int ans = sol.largestRectangleArea(h);
    cout << ans << endl;
    return 0; 
}