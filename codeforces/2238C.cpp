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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }
    vector<ll> dp(n + 1, 0);
    vector<ll> sum_dp(n + 1, 0);
    vector<int> max_h(n + 1, 0);
    vector<int> smax_h(n + 1, 0);
    vector<int> height(n + 1, 0);

    for (int i = n; i >= 1; i--) {
        dp[i] = 1 + sum_dp[i] + smax_h[i];
        height[i] = 1 + max_h[i];

        if (i > 1) {
            int parent = p[i];
            sum_dp[parent] += dp[i];
            if (height[i] > max_h[parent]) {
                smax_h[parent] = max_h[parent];
                max_h[parent] = height[i];
            } else if (height[i] > smax_h[parent]) {
                smax_h[parent] = height[i];
            }
        }
    }

    cout << dp[1] << endl; 
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
