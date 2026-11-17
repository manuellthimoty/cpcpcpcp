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

void solve(){
    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i =1 ; i <= n ; i++) cin >> a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(4,0));
    const ll INF = -(1LL << 60);
    dp[1][0] = 0;
    dp[1][1] = INF;
    dp[1][2] = INF;
    dp[1][3] = 4LL * a[1];
    for(int i = 2; i <= n ; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = max(dp[i-1][1], dp[i-1][3]);
        dp[i][1] = max(
            dp[i-1][1] + a[i],
            dp[i-1][3] + 2LL * a[i]
        );
        dp[i][3] = max(
            dp[i-1][0] + 4LL * a[i],
            dp[i-1][2] + 3LL * a[i] 
        );
    }
    ll ans = max({dp[n][0],dp[n][1],dp[n][2],dp[n][3]});
    cout << ans << endl;
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
