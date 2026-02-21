#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if (!visited[v]){
            visited[v] = true;
            dfs(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m ; cin >> n >> m;
    vector<vector<char>> a(n,vector<char> (m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    visited.resize(n*m,false);
    adj.resize(n *m);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(a[i][j] == '.'){
                int cur = i * m + j;
                if(j > 0){
                    int left = i * m + j -1;
                    if(a[i][j-1] == '.'){
                        adj[cur].push_back(left);
                    }
                }
                if(j < m-1){
                    int right = i * m + j + 1;
                    if(a[i][j+1] == '.'){
                        adj[cur].push_back(right);
                    }
                }
                if (i > 0){
                    int top = (i-1) * m + j;
                    if(a[i-1][j] == '.'){
                        adj[cur].push_back(top);
                    }
                }
                if (i < n -1){
                    int bottom = (i+1) * m + j;
                    if(a[i+1][j] == '.'){
                        adj[cur].push_back(bottom);
                    }
                }
            }
            else{
                visited[i * m + j] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n * m ; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}