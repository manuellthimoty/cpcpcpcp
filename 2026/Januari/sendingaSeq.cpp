#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool hasPathBFS(ll n, vector<vector<ll>>& adj, ll A, ll B) {
    vector<bool> visited(n, false);
    queue<ll> q;

    q.push(A);
    visited[A] = true;

    while (!q.empty()) {
        ll u = q.front(); q.pop();

        if (u == B) return true;

        for (ll v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

void debug(int n){
    cout << debug << " " << n;
}

void solve() {
    ll n ; cin >> n;
    vector<ll> a(n+1,0);

    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    
    vector<ll> dp_left (n+1,0);
    vector<ll> dp_right (n+1,0);
    for(ll i = 1 ; i <= n ; i++){
        dp_left[i] = i + a[i];
        dp_right[i] = i - a[i];
    }
    vector<vector<ll>> adj(n+2);
    for(ll i = 1 ; i <= n ; i++){
        if(dp_left[i] <= n){
            adj[i].push_back(dp_left[i] + 1);
        }
        if(dp_right[i] >=1){
            adj[dp_right[i]].push_back(i+1);
        }
    }
    
    
    ll adjSize = adj.size();
    bool ans = hasPathBFS(adjSize,adj,1,n+1);
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}