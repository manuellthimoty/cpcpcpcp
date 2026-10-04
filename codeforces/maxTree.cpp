#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> visited;
vector<ll> ans;
vector<vector<ll>> adj;

void dfs(ll v) {
    visited[v] = true;
    for (ll u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort(ll n) {
    visited.assign(n + 1, false);
    ans.clear();

    for (ll i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

void solve() {
    ll n; 
    cin >> n;

    adj.assign(n + 1, {});

    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        ll x, y; cin >> x >> y;

        // x > y artinya u > v
        if (x > y) {
            adj[v].push_back(u); // v < u
        } else {
            adj[u].push_back(v); // u < v
        }
    }

    topological_sort(n);

    // for (ll x : ans)
    //     cout << x << " ";
    // cout << "\n";

    vector<ll> finalAns(n+1,0);
    for(ll i = 0 ; i < n ; i++){
        finalAns[ans[i]] = i+1;
    }
    for(ll i = 1 ; i<= n ; i++){
        cout << finalAns[i] << " ";
    }
    cout <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
