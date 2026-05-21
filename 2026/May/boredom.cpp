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
    vector<int> a(n+1);
    for(int i =1 ; i <= n ; i++) cin >> a[i];
    map<ll,ll> cnt;
    for(int i = 1; i <= n ; i++){
        cnt[a[i]]++;
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2 ; i <= n ; i++){
        dp[i] = max((ll) dp[i-1], (ll) dp[i-2] + (ll) cnt[i] * i);
    }
    cout << dp[n] << endl;
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
