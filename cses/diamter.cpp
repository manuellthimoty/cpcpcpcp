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



int main() {
    GK();

    int n ; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ;i < n-1 ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int> d(n+1,0);
    q.push(1);
    vector<bool> visited(n+1,false);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visited[u] = true;
        for(auto v : adj[u]){
            if(!visited[v]){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    int patokan1 = 1;
    int mx = 0;
    for(int i = 1; i <= n ; i++){
        if(d[i] > mx){
            patokan1 = i;
            mx = d[i];
        }
    }
    vector<int> d2(n+1,0);
    for(int i = 0 ; i <= n ; i++) visited[i] = false;
    q.push(patokan1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visited[u] = true;
        for(auto v : adj[u]){
            if(!visited[v]){
                d2[v] = d2[u]+1;
                q.push(v);
            }
        }
    }
    int ans = 0;
    
    for(int i =1 ; i <= n ; i++){
        ans = max(ans,d2[i]);
    }
    cout << ans;
    
}
