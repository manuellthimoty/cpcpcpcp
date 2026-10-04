#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> visited;
vector<vector<int>> adjList;

void dfs(ll u){
    visited[u] = 1;
    for(int tetangga : adjList[u]){
        if(!visited[tetangga]){
            dfs(tetangga);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m ; cin >> n >> m;
    visited.assign(n+1,0);
    adjList.resize(n+1);
    while(m--){
        ll u,v ; cin >> u >> v;
        adjList[u].push_back(v);
        // adjList[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    

    return 0;
}