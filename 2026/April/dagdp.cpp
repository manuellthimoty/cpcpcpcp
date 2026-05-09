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
ll mod = 998244353;
void solve(){
    ll n,m ; cin >> n >> m;
    vector<ll> dp(n+1,0);
    vector<vector<ll>> adj(n+1);
    vector<ll> indegree(n+1,0);
    for(ll i = 0 ; i < m ; i++){
        ll u,v ; cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    dp[1] = 1;
    queue<ll> q;
    for(ll i = 1; i <= n ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto v : adj[u]){
            dp[v] = ( dp[v] + dp[u] ) % mod;
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    } 

    cout << dp[n] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
