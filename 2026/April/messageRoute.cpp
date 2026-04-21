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

void solve(){
    int n, m ; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int a,b ; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1,false);
    visited[0] = true;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> parent(n+1);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        if(f == n){
            found = true;
            break;
        }
        visited[f] = true;
        for(auto v : adj[f]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                parent[v] = f;
            }
        }
    }
    if(!found){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int cur = n;
    vector<int> ans;
    while(cur != 1){
        ans.push_back(cur);
        cur = parent[cur];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto a : ans) cout << a << " " ;
    
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
