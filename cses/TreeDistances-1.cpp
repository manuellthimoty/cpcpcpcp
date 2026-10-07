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

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < n-1 ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto bfs = [&](int start){
        queue<int> q1;
        vector<int> d1(n+1,-1);
        d1[start] = 0;
        q1.push(start);
        while(!q1.empty()){
            int u = q1.front();
            q1.pop();
            for(auto v : adj[u]){
                if(d1[v] == -1){
                    d1[v] = d1[u]+1;
                    q1.push(v);
                }
            }
        }
        return d1;
    };

    vector<int> d1 = bfs(1);
    int ujungkiri = 1;
    int curmx = 0;
    for(int i = 1; i <= n ; i++){
        if(d1[i] > curmx){
            curmx = d1[i];
            ujungkiri = i;
        }
    }

    vector<int> d_kiri = bfs(ujungkiri);
    int ujungkanan = ujungkiri;
    curmx = 0;
    for(int i =1 ; i <= n ; i++){
        if(d_kiri[i] > curmx){
            curmx = d_kiri[i];
            ujungkanan = i;
        }
    }
    
    vector<int> d_kanan = bfs(ujungkanan);
    for(int i = 1; i <= n ; i++){
        cout << max(d_kiri[i],d_kanan[i]) << " ";
    }



    return 0;
}
