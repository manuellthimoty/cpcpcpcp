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
vector<vector<int>> adj;
vector<bool> visited;
vector<int> val;
vector<int> path;
vector<int> nodes;
int n;
void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    path.push_back(u);
}

void dfs2(int u, int nilai){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs2(v,nilai+1);
        }
    }
    val[u] = nilai;
}

void topological_sort(){
    visited.assign(n+1,false);
    path.clear();
    for(auto i : nodes){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(path.begin(),path.end());
}

void solve(){
    nodes.clear();
    cin >> n;
    vector<int> a(n+1);
    input(a,1,n+1);
    string s; s.resize(n);
    string newss; cin >> newss;
    s = '#' + newss;
    val.clear();
    val.resize(n+1,0);
    vector<pair<int,int>> same;
    int first = 0;
    int last = 0;
    bool streak = false;
    
    for(int i = 1 ; i <= n ; i++){
        if(s[i] == '='){
            if(streak){
                last = i;
            }
            else{
                first = i;
                last = i;
                streak = true;
            }
        }
        else{
            if(streak){
                same.push_back(make_pair(first, last));
            }
            streak = false;
        }
    }
    
    // Handle jika streak masih berlangsung sampai akhir string
    if(streak){
        same.push_back(make_pair(first, last));
    }


    adj.resize(n+1);
    visited.resize(n+1,false);
    streak = false;
    vint ref(n+1);
    vector<bool> unique(n+1,true);
    for(int i = 1; i <= n ; i++) ref[i] = i;
    for(auto p : same){
        for(int i = p.first ; i <= p.second+1 ; i++){
            ref[i] = p.first;
            if(i > p.first) unique[i] = false;
        }
    }

    for(int i = 1; i <= n ; i++){
        if(unique[i]) nodes.push_back(i);
    }

   
    
    for(int i = 1 ; i <= n ; i++){
        if(s[i] == '<'){
            adj[ref[i]].push_back(ref[i+1]);
        } //  b[i] < b[i+1]
        else if(s[i] == '>'){
            adj[ref[i+1]].push_back(ref[i]);
        }
    }

    path.resize(n+1);
    topological_sort();
    // for(auto p : nodes) cout << p << " ";
    visited.assign(n+1,false);
    val.assign(n+1,1);
    for(auto p : path){
        for(auto v : adj[p]){
            val[v] = max(val[v],val[p]+1);
        }
    }
    vector<int> b(n+1);
    for(int i = 1; i <= n ; i++){
        if(unique[i]) b[i] = val[i];
    }
    for(int i = 1; i <= n ; i++){
        if(!unique[i]) b[i] = val[ref[i]];
    }
    ll total = 0;
    for(int i = 1; i <= n ; i++) total += (ll) a[i] * b[i];
    cout << total << endl;
    for(int i = 1 ; i <= n ; i++) cout << b[i] << " ";


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
