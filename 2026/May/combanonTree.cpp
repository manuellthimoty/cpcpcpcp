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
    int n ; cin >> n;
    vector<int> bobot(n+1);
    vector<vector<int>> adj_awal(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> bobot[i];
    
    for(int i = 0 ; i < n-1 ; i++){
        int u,v; cin >> u >> v;
        adj_awal[u].push_back(v);
        adj_awal[v].push_back(u);
    }
    
    vector<int> dp(n+1,0);
    vector<vector<int>> adj_anak(n+1); 
    vector<bool> vis(n+1, false);
    
    queue<int> q;
    q.push(1);
    vis[1] = true;
    vector<int> urutan;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        urutan.push_back(f);
        
        for(auto v : adj_awal[f]){
            if(!vis[v]){
                vis[v] = true;
                adj_anak[f].push_back(v);
                q.push(v);
            }
        }
    }
    
    while(!urutan.empty()){
        int lst = urutan.back();
        urutan.pop_back();
        
        ll sum_down = 0;
        for(auto v : adj_anak[lst]){
            sum_down += dp[v];
        }
        
        if(bobot[lst] == 1){
            if(sum_down % 2 == 0){
                dp[lst] = sum_down;
            } else{
                dp[lst] = 1 + sum_down;
            }
        }
        else{
            if(sum_down % 2 == 0){
                dp[lst] = sum_down + 1;
            } else{
                dp[lst] = sum_down;
            }
        }
    }
    cout << dp[1] << endl;
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
