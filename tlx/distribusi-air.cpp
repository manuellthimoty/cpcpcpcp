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

struct DSU {
    vector<int> parent, sz;
    ll total;
    DSU(int n) {
        parent.resize(n);
        total = 0;
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        int copya = a;
        int copyb = b;
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        total -= 1LL * sz[a] * (sz[a] - 1) / 2;
        total -= 1LL * sz[b] * (sz[b] - 1) / 2;
        sz[a] += sz[b];
        total += 1LL * sz[a] * (sz[a] - 1) / 2;
        return true;
    }
    
};

void solve(){
    ll n,m,q; cin >> n >> m >> q;
    vector<pair<ll,pair<ll,ll>>> adj(m+1);
    DSU dsu(n);
    vector<bool> mark(m+1,false);
    for(int i = 1; i <= m ; i++){
        ll x,y,z; cin >> x  >> y >> z;
        adj[i] = {x,{y,z}};
        if(z == 1){
            mark[i] = true;
        }
    }
    vector<pair<char,int>> queries;
    for(int i = 0 ; i < q; i++){
        char op;
        ll p;
        cin >> op >> p;
        queries.push_back({op,p});
        mark[p] = false;
    }
    for(int i = 1 ; i <= m ; i++){
        if(mark[i]){
            int u = adj[i].first;
            int v = adj[i].second.first;
            u--;v--;
            dsu.unite(u,v);
        }
    }
    ll curtot = dsu.total;
    // cout << dsu.total << '\n';
    vector<ll> ans;
    for(int i = q-1; i >= 1 ; i--){
        int id = queries[i].second;
        int u = adj[id].first;
        int v = adj[id].second.first;
        u--;
        v--;
        dsu.unite(u,v);
        // cout << dsu.total << '\n';
        ans.push_back(dsu.total);
    }
    reverse(ans.begin(),ans.end());
    for(auto &x : ans) cout << x << '\n';
    cout << curtot;
}
int main() {
    GK();

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
