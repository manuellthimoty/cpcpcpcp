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

    ll n ; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n ; i++) cin >> a[i];
    // dp[i][j] = max(dp[i-1][j-1] + a[i],dp[i-1][j])
    vector<vector<ll>> dp(n,vector<ll>(n+1,-1e9));
    dp[0][1] = a[0];
    dp[0][0] = 0;
    for(int i = 1; i < n ; i++){
        for(int j = 0 ; j <= i+1 ; j++){
            if(j == 0){
                dp[i][j] = 0;
                continue;
            }
            if(dp[i-1][j-1] >= 0){
                if(a[i] + dp[i-1][j-1] >= 0){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + a[i]);
                }
            }
            if(dp[i-1][j] >= 0){
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
            // dp[i][j] = max(dp[i-1][j-1] + a[i],dp[i-1][j]);
        }
    }
    // for(int i = 1 ; i < n ; i++){
    //     cout << i << " : ";
    //     for(int j = 0 ; j <= i+1 ; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int cnt = 0;
    for(int i = 0 ; i <= n ; i++){
        if(dp[n-1][i] >= 0) cnt = max(cnt,i);
    }
    cout << cnt;

    return 0;
}
