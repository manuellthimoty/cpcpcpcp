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

void solve(){
    int n ; cin >> n;
    vint a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vint dp(n);
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for(int i = 2; i < n ; i++){
        dp[i] = min(dp[i-2] + abs(a[i] - a[i-2]),dp[i-1] + abs(a[i]-a[i-1]));
    }
    cout << dp[n-1] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
