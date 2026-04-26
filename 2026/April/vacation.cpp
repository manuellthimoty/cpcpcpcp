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
    int n ; cin >> n ;
    vint a(n),b(n),c(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(n,vector<int>(3));
    dp[0][0] = a[0]; dp[0][1] = b[0]; dp[0][2] = c[0]; 
    for(int i = 1 ; i < n ; i++){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + c[i];
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
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
