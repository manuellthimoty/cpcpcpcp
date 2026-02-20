#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

bool adjacent(int x, int y){
    if(x == y) return false;
    if(x + y == 7) return false;
    return true;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(7, INF));
    for(int v = 1; v <= 6; v++)
        dp[1][v] = (a[1] != v);

    for(int i = 2; i <= n; i++){
        for(int v = 1; v <= 6; v++){
            for(int u = 1; u <= 6; u++){
                if(adjacent(u, v)){
                    dp[i][v] = min(dp[i][v],
                                   dp[i-1][u] + (a[i] != v));
                }
            }
        }
    }

    int ans = INF;
    for(int v = 1; v <= 6; v++)
        ans = min(ans, dp[n][v]);

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}
