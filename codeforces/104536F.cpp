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

pair<int, int> extract(vector<vector<int>>& adj, int n) {
    auto bfs = [&](int start) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    vector<int> dist1 = bfs(1);
    int A = 1;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > dist1[A]) A = i;
    }

    vector<int> distA = bfs(A);
    int B = A;
    for (int i = 1; i <= n; i++) {
        if (distA[i] > distA[B]) B = i;
    }
    int diameter = distA[B];
    vector<int> distB = bfs(B);
    int min_h = n;
    for (int i = 1; i <= n; i++) {
        int h_i = max(distA[i], distB[i]);
        min_h = min(min_h, h_i);
    }
    return {diameter, min_h};
}


int main() {
    GK();

    int n ; cin >> n;
    vector<vector<int>> adjn(n+1);
    for(int i = 0 ; i < n-1 ; i++){
        int u,v; cin >> u >> v;
        adjn[u].push_back(v);
        adjn[v].push_back(u);
    }
    int m ; cin >> m;
    vector<vector<int>> adjm(m+1);
    for(int i = 0 ; i < m-1 ; i++){
        int u,v; cin >> u >> v;
        adjm[u].push_back(v);
        adjm[v].push_back(u);      
    }

    pair<int,int> p1 = extract(adjn,n);
    pair<int,int> p2 = extract(adjm,m);

    int ans = max({p1.first,p2.first,p1.second+p2.second+1});
    cout << ans;
    return 0;
}
