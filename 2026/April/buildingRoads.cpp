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
void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}


void solve(){
    int n,m ; cin >> n >> m;
    visited.resize(n+1,false);
    visited[0] = true;
    adj.resize(n+1);
    for(int i = 0 ; i < m ; i++){
        int a,b ; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> kelompok;
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        if(visited[i]) continue;
        else{
            dfs(i);
            count++;
            kelompok.push_back(i);
        }
    }

    cout << count-1 << endl;
    int bnyk = kelompok.size();
    for(int i = 0 ; i < bnyk-1 ; i++){
        cout << kelompok[i] << " " << kelompok[i+1];
        cout << endl;
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
