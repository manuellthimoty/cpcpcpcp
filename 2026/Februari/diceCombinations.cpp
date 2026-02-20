#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> val = {1,2,3,4,5,6};
ll M = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n ; cin >> n;
    vector<vector<ll>> dp(7,vector<ll>(n+1,0));
    for(ll i = 0 ; i <= 6 ; i++){
        dp[i][0] = 1;
    }
    for(ll j = 0 ; j <= n ; j++){
        for(ll i = 1 ; i <= 6 ; i++){
            dp[i][j] = dp[i-1][j];
            if(j - i >= 0){
                dp[i][j] = (dp[i][j] + dp[6][j-i]) % M;
            }
        }
    }
    cout << dp[6][n] << endl;
    return 0;
}
