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
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)

int n, k;

vector<int> curr;
vector<vector<bool>> dp;
int cnt = 0;
void dfs(int i, int rem) {

    if (i == n + 1) {
        if (rem == 0) {
            for (int x : curr) cout << x << ' ';
            cout << '\n';
            cnt++;
        }
        return;
    }
    for (int x = 0; i * x <= rem; x++) {
        int newRem = rem - i * x;
        if (dp[i + 1][newRem]) {
            curr.push_back(x);
            dfs(i + 1, newRem);
            curr.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    dp.assign(n + 2, vector<bool>(k + 1, false));
    dp[n + 1][0] = true;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= i) {
                dp[i][j] = dp[i][j] || dp[i][j - i];
            }
        }
    }
    if (!dp[1][k]) return 0;

    dfs(1, k);
    cout << endl;
    cout << cnt;
    return 0;
}