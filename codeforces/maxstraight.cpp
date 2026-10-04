#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            visited[v] = true;
            dfs(v);
        }
    }
}

void solve(){
    int n ; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    map<int,int> dp;
    int ans = 1;
    for(int i = 1; i <= n ;i++){
        int cur = a[i];
        if(dp.find(cur-1) != dp.end()){
            dp[cur] = max(dp[cur],dp[cur-1] +1);
        }
        else{
            dp[cur] = max(dp[cur],1);
        }
        ans = max(ans,dp[cur]);
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
