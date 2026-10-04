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
const int maxN = 1e5;
int d[maxN+1];
bool isTarget[maxN+1];
vector<vector<int>> adj;

void dfs(int u, int parent){
    d[u] = isTarget[u];
    for(auto v : adj[u]){
        dfs(v,u);
        d[u] += d[v];
    }
}
vector<int> ans;

void dfs2(int u){
    vector<int> val;
    for(auto v : adj[u]){
        if(d[v] > 0){
            val.push_back(v);
        }
    }
    int total_route = val.size() + (isTarget[u] ? 1 : 0);
    if(isTarget[u]){
        for(auto x : val){
            ans.push_back(x);
            if(d[x] > 1) dfs2(x);
        }
    }
    else{
        for(int i = 0 ; i < val.size() -1 ; i++){
            int x = val[i];
            ans.push_back(x);
            if(d[x] > 1){
                dfs2(x);
            }
        }
        int x_skip = val.back();
        if(d[x_skip] > 1){
            dfs2(x_skip);
        }
    }
}

void solve(){
    ans.clear();
    int n ; cin >> n;
    vector<int> p(n);
    adj.assign(n + 1, vector<int>());
    for(int i = 2 ; i <= n; i++){
        int p; cin >> p;
        adj[p].push_back(i);
    }
    int m; cin >> m;
    vector<int> a(m+1);
    for(int i = 1; i <= m ; i++) cin >> a[i];
    for(int i = 1; i <= m ; i++){
        isTarget[a[i]] = true;
    }

    dfs(1,-1);
    if(d[1] > 1){
        dfs2(1);
    }
    cout << m-1 << ' ';
    for(auto a : ans){
        cout << a << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= m ; i++){
        isTarget[a[i]] = false;
    }
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
