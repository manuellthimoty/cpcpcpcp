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
#define GK() ios::sync_with_stdio(false);cin.tie(nullptr)


vector<bool> visited;
vector<int> sz;
vector<int> d;
vector<vector<int>> adj;
vector<ll> ans;
int n;
void dfs(int u, ll depth){
    visited[u] = true;
    sz[u] = 1;
    ans[1] += depth;
    
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v,depth);
            sz[u] += sz[v];
        }
    }
}


void dfs2(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n+1);
    for(int i = 0; i < n -1 ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.resize(n+1,false);
    sz.resize(n+1,0);

    dfs(1,0);
    visited.assign(n+1,false);

    dfs2(1);
    for(int i = 1; i <= n ; i++) cout << ans[i] << " ";



    return 0;
}
