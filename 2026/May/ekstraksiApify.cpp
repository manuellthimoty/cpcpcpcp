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
    ll n,m ; cin >> n >> m;
    int p ; cin >> p;
    vector<vector<ll>> s(n+1,vector<ll> (m+1));
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(p+1,0)));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> s[i][j];
        }
    }
    dp[0][0][0] = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            for(int k = 0 ; k <= p ; k++){
                if(k == 0) dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k]) + s[i][j];
                if(s[i][j] >= 0) dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k]) + s[i][j];
                else{
                    if(k <= p){
                        dp[i][j][k] = max(dp[i-1][j][k-1],dp[i][j-1][k-1]);
                    }
                    dp[i][j][k] = max(dp[i][j][k],max(dp[i-1][j][k],dp[i][j-1][k]) + s[i][j]);
                }
            }
        }
    }
    ll ans = 0;
    for(int k = 0 ; k <= p ; k++){
        ans = max(dp[n][m][k], ans);
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
