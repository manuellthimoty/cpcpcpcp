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
    vector<pair<int,int>> pos(n);
    vector<int> x(n),h(n);
    for(int i = 0 ; i < n ; i++){
        cin >> x[i] >> h[i];
    }
    vector<vector<int>> dp(n,vector<int>(3));
    // 0 jika ga jatuh
    // 1 jika jatuh ke kiri
    // 2 jika jatuh ke kanan
    // dp[i][k] = banyaknya cr maks jika diketahui pohon 1,2,...,i dan pohon ke i jatuh
    // ke arah k
    // transisi : 
    // dp[i][0] = max(dp[i-1][0],dp[i-1][1],dp[i-1][2])
    // dp[i][1]
    // jika i-1 ga jatuh ke kanan : syaratnya adalah xi - hi >= x[i-1]
    // jika i-1 jatuh ke kanan : xi -hi >= x[i-1] + h[i-1]
    // dp[i][1] = dp[i-1][1] + 1 if xi-hi >= x[i-1] + h[i--1]
    // dp[i][2]. Karena kiri ga berpengaruh, maka jika x[i] + h[i] < x[i+1], maka
    // dp[i][2] = max(dp[i-1][0],dp[i-1][1],dp[i-1][2]) + 1; selain itu, 9
    dp[0][0] = 0; dp[0][1] = 1; dp[0][2] = (x[0] + h[0]) < x[1] ? 1 : 0;
    for(int i = 1; i < n ; i++){
        dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        dp[i][1] = 0;
        if(x[i] - h[i] > x[i-1]){
            dp[i][1] = max({dp[i][1],dp[i-1][0] + 1,dp[i-1][1] + 1});
        }
        if(x[i]-h[i] > (x[i-1] + h[i-1])){
            dp[i][1] =max(dp[i][1], dp[i-1][2] + 1);
        }
        dp[i][2] = 0;
        if(i == n-1){
            dp[i][2] = 1 + max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        }
        else if(x[i] + h[i] < x[i+1]){
            dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + 1;
        }
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << endl;
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
