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


int main() {
    GK();
    int n,k; cin >> n >> k;
    ll MOD = 998244353;
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));

    dp[0][0] = 0;
    dp[1][0] = 1;
    for(int i = 2; i <= n ; i++){
        dp[i][0] = dp[i-1][0] * 2;
        dp[i][0] %= MOD;
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= k ; j++){
            dp[i][j] = (dp[i-1][j] %MOD * (2 * j +2) % MOD) %MOD + (dp[i-1][j-1] %MOD  * (i-2*j) %MOD) %MOD;
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][k];

    return 0;
}
