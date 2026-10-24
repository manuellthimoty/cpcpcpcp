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
    vector<vector<int>> d(n+1,vector<int>(n+1));
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> d[i][j];
        }
    }
    vector<pair<int,int>> v1;
    for(int i = 1 ; i <= n ; i++) v1.push_back({d[1][i],i});
    // sort(d.begin()+1,d.end());
    sort(v1.begin(),v1.end());
    vector<int> par(n+1,-1);
    par[1] = 1;
    vector<int> done;
    done.push_back(1);

    vector<vector<pair<ll,ll>>> adj(n+1);

    bool oke = true;
    for(int i = 1; i < n ; i++){
        ll curid = v1[i].second;
        ll curlen = v1[i].first;

        if(par[curid] != -1) continue;
        ll mn = 2e9+1;
        bool found = false;
        ll nxt = -1;
        for(auto x : done){
            if(curlen == (d[1][x] + d[x][curid])){
                found = true;
                if(nxt == -1 || d[x][curid] < mn){
                    nxt = x;
                    mn = d[x][curid];
                }
            }
        }
        if(nxt == -1 || mn <= 0){
            oke = false;
            break;
        }
        par[curid] = nxt;
        done.push_back(curid);

        adj[nxt].push_back({curid,mn});
        adj[curid].push_back({nxt,mn});
    }

    if(!oke){
        cout << "No" << endl;
        return 0;
    }
    // cout << "YES" << endl;
    for(int i = 1; i <= n ; i++){
        vector<ll> dst(n+1,-1);
        queue<int> q;
        q.push(i);
        dst[i] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto e : adj[u]){
                int v = e.first;
                ll w = e.second;
                if(dst[v] == -1){
                    dst[v] = dst[u] + w;
                    q.push(v);
                }
            }
        }

        for(int j = 1; j <= n ; j++){
            if(dst[j] != d[i][j]){
                oke = false;
                break;
            }
        }
        if(!oke) break;
    }
    if(!oke){
        cout << "No";
    }
    else cout << "Yes";

    

    return 0;
}
