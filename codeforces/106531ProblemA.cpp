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


// let dp[i][k] = max point he can get if last day i and he choose from i to i - k+1;
// then dp[i][k] = f[i-k+1,i] - k ^ 2 + max(dp[i-k],dp[i-k-1],...,dp[0]);
// 
void solve(){
    int n ; cin >> n;
    vector<ll> a(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    vector<ll> pref(n+1);
    pref[0] = 0;
    for(int i =1 ; i <= n ; i++){
        pref[i] = pref[i-1] + a[i];
    }
    vector<ll> dp(n+1);
    dp[0] = 0;
    for(int i = 1; i <= n ; i++){
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], pref[i] - i * i);
        for(int k = 1 ; k <i ; k++){
            dp[i] = max(dp[i],dp[k-1] + pref[i] - pref[k] - (i-k) * (i-k));
        }
    }

    ll ans = dp[1];
    for(int i = 1; i <= n ; i++){    
        ans = max(ans,dp[i]);

    }
    cout << ans << endl;
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
