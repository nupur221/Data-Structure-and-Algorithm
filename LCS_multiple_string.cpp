#include <bits/stdc++.h>
using namespace std;
const int mxn = 52; 
int dp[mxn][mxn][mxn];


string findLCS(const vector<string>& s) {
    int n = s.size();
    vector<int> sz(n);
    for (int i = 0; i < n; ++i) {
        sz[i] = s[i].size();
    }
    memset(dp, 0, sizeof(dp));
    for (int i1 = 1; i1 <= sz[0]; i1++) {
        for (int i2 = 1; i2 <= sz[1]; i2++) {
            for (int i3 = 1; i3 <= sz[2]; i3++) {
                if (s[0][i1 - 1] == s[1][i2 - 1] && s[1][i2 - 1] == s[2][i3 - 1]) {
                    dp[i1][i2][i3] = dp[i1 - 1][i2 - 1][i3 - 1] + 1;
                } else {
                    dp[i1][i2][i3] = max({dp[i1 - 1][i2][i3], dp[i1][i2 - 1][i3], dp[i1][i2][i3 - 1]});
                }
            }
        }
    }
    string lcs = "";
    int i1 = sz[0], i2 = sz[1], i3 = sz[2];
    while (i1 > 0 && i2 > 0 && i3 > 0) {
        if (s[0][i1 - 1] == s[1][i2 - 1] && s[1][i2 - 1] == s[2][i3 - 1]) {
            lcs += s[0][i1 - 1];
            i1--;
            i2--;
            i3--;
        } else if (dp[i1 - 1][i2][i3] == dp[i1][i2][i3]) {
            i1--;
        } else if (dp[i1][i2 - 1][i3] == dp[i1][i2][i3]) {
            i2--;
        } else {
            i3--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            getline(cin, s[i]);
        }       
        string lcs = s[0];
        for (int i = 1; i < n; i++) {
            lcs = findLCS({lcs, s[i], s[i]}); 
        }
        cout << lcs.size() << endl;
        if (!lcs.empty()) {
            cout << lcs << endl;
        }
    }
    return 0;
}
