#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define vll vector<ll>
#define vint vector<int>
#define input(a,l,r) for(int i = l ; i < r ; i++) cin >> a[i];
#define REP(i,l,r) for(int i = l ; i < r ; i++)
#define REPLL(i,l,r) for(ll i = l ; i < r ; i++)

int getLCS(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Match found
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); // Mismatch
            }
        }
    }

    std::vector<int> lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (arr1[i - 1] == arr2[j - 1]) {
            lcs.push_back(arr1[i - 1]); // Element is part of LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    std::reverse(lcs.begin(), lcs.end());
    return lcs.size();
}
void solve() {
    string a, b;
    cin >> a >> b;
    
    int n = a.size();
    int m = b.size();
    vector<int> pA(n);
    vector<int> pB(m);
    
    pA[0] = a[0] - '0';
    for(int i = 1; i < n; i++) {
        pA[i] = (pA[i-1] + (a[i] - '0')) % 10;
    }
    
    pB[0] = b[0] - '0';
    for(int i = 1; i < m; i++) {
        pB[i] = (pB[i-1] + (b[i] - '0')) % 10;
    }

    if (pA[n - 1] != pB[m - 1]) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (pA[i - 1] == pB[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
    }
    cout << dp[n - 1][m - 1] + 1 << endl;
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
