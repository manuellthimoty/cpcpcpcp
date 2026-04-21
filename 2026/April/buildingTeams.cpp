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
vector<bool> visited;
vector<vector<int>> adj;
vector<int> col;
bool dfs(int u, int parent){
    visited[u] = true;
    for(auto v: adj[u]){
        if(!visited[v]){
            if(dfs(v,u)){
                return true;
            }
        }
        else if(v != parent){
            return true;
        }
    }
    return false;
}

bool hascycle(int n){
    visited.assign(n+1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(dfs(i,-1)){
                return true;
            }
        }
    }
    return false;
}

void dfs2(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            if(col[u] == 1) col[v] = 2;
            if(col[u] == 2) col[u] = 1;
            dfs2(v);
        }
    }
}

void solve(){
    int n,m ; cin >> n >> m;
    visited.resize(n+1);
    adj.resize(n+1);
    for(int i =0 ; i < m ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(hascycle(n)){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    visited.assign(n+1,false);
    visited[0] = true;
    col.resize(n+1,0);
    for(int i = 1; i <= n ; i++){
        if(!visited[i]){
            col[i] = 1;
            dfs2(i);
        }
    }
    for(int i = 1; i <= n ; i++){
        cout << col[i] << " ";
    }

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
