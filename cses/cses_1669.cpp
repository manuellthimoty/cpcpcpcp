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

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;

int startC = -1;
int endC = -1;

bool dfs(int u, int par){
    visited[u] = true;
    for(int v : adj[u]){
        if(v == par) continue;
        if(visited[v]){
            startC = v;
            endC = u;
            return true;
        }
        parent[v] = u;
        if(dfs(v,parent[v])){
            return true;
        }
    }
    return false;
}

int main() {
    GK();

    int n ; cin >> n;

    int m ; cin >> m;
    adj.resize(n);
    parent.resize(n,-1);
    visited.resize(n,false);
    for(int i = 0 ; i < m ; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int u = 0 ; u < n ; u++){
        if(!visited[u] && dfs(u,parent[u])){
            break;
        }
    }

    if(startC == -1){
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int> cycle;
        cycle.push_back(startC);
        for(int v = endC ; v != startC; v = parent[v]){
            cycle.push_back(v);
        }
        
        cycle.push_back(startC);
        cout << cycle.size() << endl;
        for(int u : cycle){
            cout << u+1 << " ";
        }
    }
    return 0;
}
