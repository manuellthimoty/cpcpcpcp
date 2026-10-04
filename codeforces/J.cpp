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
    int n; cin >> n;
    int m ; cin >> m;
    vector<int> robot(n+1);
    vector<pair<int,int>> kios(m+1);
    for(int i = 1 ; i<= n ; i++) cin >> robot[i];
    for(int i = 1 ; i <= m ; i++){
        int s,c; cin >> s >> c;
        kios[i] = {s,c};
    }
    sort(robot.begin() + 1, robot.end());
    sort(kios.begin() + 1,kios.end());
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    dp[0][0] = 0;
    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j<= m ; j++){
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + kios[j].second - abs(kios[j].first - robot[i]));
        }
    }
    cout << dp[n][m] << endl;

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
