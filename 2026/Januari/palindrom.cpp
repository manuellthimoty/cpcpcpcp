#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n,vector<int> (n));
    for(int len = 1 ; len <= n ; len++){
        for(int i = 0 ; i < n ; i++){
            if(len == 1){
                dp[i][i] = 1;
                continue;
            }
            int j = i + len - 1;
            if(j > n - 1) break;
            if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}