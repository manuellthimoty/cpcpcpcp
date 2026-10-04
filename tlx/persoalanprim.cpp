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
    int n,m ; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
    }
    ll oks = true;
    int cnt = 0;
    if(adj[1].size() != n-1){
        cout << -1 << endl;
        return;
    }
    vector<int> bobot1(n+1);
    for(auto v : adj[1]){
        int idx = v.first;
        int val = v.second;
        bobot1[idx] = val;
    }
    for(int i = 2 ; i <= n ; i++){
        for(auto v : adj[i]){
            int curidx = v.first;
            int curbobot = v.second;
            if (curbobot < bobot1[i] || curbobot < bobot1[curidx]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
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
