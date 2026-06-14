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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m ; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int u,v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> col(n+1,-1);
    bool oks = true;
    queue<int> q;
    for(int i = 0 ; i < n ; i++){
        if(col[i] == -1){
            // belum diwarnai apa apa
            q.push(i);
            col[i] = 0;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(auto u : adj[v]){
                    if(col[u] == -1){
                        col[u] = col[v] ^ 1;
                        q.push(u);
                    }
                    else{
                        oks = oks & (col[u] != col[v]);
                    }
                }
            }
        }
    }
    if(oks){
        for(int i =  1; i <= n ; i++){
            cout << col[i] + 1 << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }

    return 0;
}
