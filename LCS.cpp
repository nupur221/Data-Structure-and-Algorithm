// .................LCS print string and size for two string............

// #include <bits/stdc++.h>
// using namespace std;
// const int mxn = 3001; 
// int dp[mxn][mxn];

// string LCS(string& s, string& t) {
//     int n = s.size();
//     int m = t.size();   
//     memset(dp, 0, sizeof(dp));
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//             else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//         }
//     }
//     string lcs = "";
//     int i = n, j = m;
//     while (i > 0 && j > 0) {
//         if (s[i - 1] == t[j - 1]) {
//             lcs = s[i - 1] + lcs; 
//             i--;
//             j--;
//         } else if (dp[i - 1][j] > dp[i][j - 1])  i--;
//         else j--;
//     }

//     return lcs;
// }

// int main() {
//     string s, t;
//     cin >> s >> t;
//     //int ans = LCS(s,t).size();
//     string lcss = LCS(s, t);
//     //cout << ans << endl;
//     cout << lcss << endl;

//     return 0;
// }








#include <bits/stdc++.h>
#define fast()  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const int mxn = 3001; 
int dp[mxn][mxn];

string LCS(string& s, string& t) {
    int n = s.size();
    int m = t.size();   
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs = s[i - 1] + lcs; 
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])  i--;
        else j--;
    }

    return lcs;
}

int main() {
    fast();
    string s, t;
    while(cin >> s >> t){
        string lcss = LCS(s, t);
        if(!lcss.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}
