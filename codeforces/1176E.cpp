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

void solve(){
    int n ; cin >> n;
    int m ; cin >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    vector<int> d(n+1,-1);
    q.push(1);
    d[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] == -1){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    vector<int> even,odd;
    for(int i = 1; i <= n ; i++){
        if(d[i] % 2 == 1) odd.push_back(i);
        else even.push_back(i);
    }
    if(even.size() <= odd.size()){
        cout << even.size() << endl;
        for(auto x : even) cout << x << ' ';
    }
    else{
        cout << odd.size() << endl;
        for(auto x : odd) cout << x << ' ';
    }
    cout << endl;
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
