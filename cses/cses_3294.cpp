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

    int n ; cin >> n ;
    int m ; cin >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    // pref
    while(m--){
        ll l,r,s; cin >> l >> r >> s;
        adj[l-1].push_back({r,s});
        adj[r].push_back({l-1,-s});
    }
    vector<ll> pref(n+1,0);
    vector<bool> visited(n+1,false);
    bool oks = true;

    for(int i = 0; i <= n ; i++){
        if(visited[i]) continue;
        visited[i] = true;
        pref[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty() && oks){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                ll to = v.first;
                ll w = v.second;
                if(!visited[to]){
                    visited[to] = true;
                    pref[to] = pref[u] + w;
                    q.push(to);
                }
                else{
                    if(pref[to] != pref[u] + w){
                        oks =false;
                        break;
                    }
                }
            }
        }
    }

    if(!oks){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        for(int i = 1; i <= n ; i++){
            ll xi = pref[i] - pref[i-1];
            cout << xi << " ";
        }
    }

    return 0;
}
