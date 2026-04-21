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
vector<bool> visited;
vector<vector<int>> adj;

int n, m ; 

void solve(){
    int start = -1; int dest = -1;
    cin >> n >> m;
    adj.resize(n*m);
    visited.resize(n*m,false);
    vector<string> s(n);
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int cur = m * (i) + j;
            if(s[i][j] == '#') continue;
            if(s[i][j] == 'A') start = cur;
            if(s[i][j] == 'B') dest = cur;
            if(i > 0) if(s[i-1][j] != '#') adj[cur].push_back(m*(i-1) + j);    
            if(i < n-1) if(s[i+1][j] != '#') adj[cur].push_back(m*(i+1)+j);
            if(j > 0) if(s[i][j-1] != '#') adj[cur].push_back(m*i + j-1);
            if(j < m-1) if(s[i][j+1] != '#') adj[cur].push_back(m*i + j + 1);
        }
    }
    queue<int> q;
    q.push(start);
    visited[start] = true;
    vector<int> parent(n*m,-1);
    vector<char> move_dir(n*m);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == dest) break;
        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                if(v == u-1) move_dir[v] = 'L';
                else if(v == u+1) move_dir[v] = 'R';
                else if(v == u+m) move_dir[v] = 'D';
                else if(v == u-m) move_dir[v] = 'U';

                q.push(v);
            }
        }
    }

    if(!visited[dest]) {
        cout << "NO" << endl;
        return;
    }

    string path = "";
    int cur =dest;
    while(cur != start){
        path.push_back(move_dir[cur]);
        cur = parent[cur];
    }
    reverse(path.begin(),path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
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
