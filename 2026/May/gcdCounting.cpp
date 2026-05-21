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
// dfs 2 kali
int n;
vector<vector<int>> adj;
vector<int> a;
int MAX_VAL = 2e5;
vector<int> distv;
int curbfs = 0;
vector<int> curstate;
vector<bool> is_prime(MAX_VAL+1, true);
vector<int> primes;
void build_sieve() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; i <= MAX_VAL; i++) {
        if (is_prime[i] && (ll)i * i <= MAX_VAL) {
            for (int j = i * i; j <= MAX_VAL; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i <= MAX_VAL ; i++){
        if(is_prime[i]) primes.push_back(i);
    }
}

// vector<bool> visited(n+1);
vector<int> visited(n+1,0);

int hitung(int u, int prima){
    queue<int> q;
    // vector<int> distance(n+1,-1);
    distv[u] = 0;
    q.push(u);
    visited[u] = prima;
    
    int max_distance = 0;
    int terjauh = u;
    while(!q.empty()){
        int curr = q.front();
        visited[curr] = true;
        q.pop();
        curstate[curr] = 1;
        for(int v : adj[curr]){
            if(a[v] % prima == 0 && visited[v] != prima && curstate[v] != 1){
                distv[v] = distv[curr] + 1;
                q.push(v);
                visited[v] = prima;
                curstate[v] = 1;
                if(distv[v] > max_distance){
                    max_distance = distv[v];
                    terjauh = v;
                }
            }
        }
    }
    // skrg udh punya terjauh, bfs sekali lagi
    int max_distance_2 = 0;
    int terjauh_2 = 0;      
    queue<int> q2;
    q2.push(terjauh);
    // distv.assign(n+1,-1);
    distv[terjauh] = 0;
    
    while(!q2.empty()){
        int curr = q2.front();
        // visited[curr] = true;
        q2.pop();
        curstate[curr] = 2;
        for(int v : adj[curr]){
            if(a[v] % prima == 0 && curstate[v] != 2){
                distv[v] = distv[curr] + 1;
                q2.push(v);
                curstate[v] = 2;
                
                if(distv[v] > max_distance_2){
                    max_distance_2 = distv[v];
                    terjauh_2 = v;
                }
            }
        }
    }
    return max_distance_2;
}

void solve(){
    cin >> n;
    visited.resize(n+1,false);
    adj.resize(n+1);
    a.resize(n+1);
    curstate.assign(n+1,0);
    distv.assign(n+1,0);
    int ans = 0;

    for(int i = 1; i <= n ; i++){
        cin >> a[i];
        if(a[i] > 1) ans = 1;
    }
    for(int i = 0 ; i < n-1 ; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<vector<ll>> nodeP(MAX_VAL+1);
    for(int i = 1 ; i <= n ; i++){
        int temp = a[i];
        for(auto p : primes){
            if(temp % p == 0){
                nodeP[p].push_back(i);
                while(temp % p == 0){
                    temp = temp/p;
                }
            }
        }
    }

    vector<int> validP;
    for(int i = 1 ; i <= MAX_VAL ; i++){
        if(nodeP[i].size() > 0){
            validP.push_back(i);
        }
    }
    for(auto val : validP){
        // val : nodeP[val] sizenya > 0
        vector<ll> curList = nodeP[val];
        int mx = 0;
        for(auto u : curList){
            if(visited[u] != val){
                mx = max(mx, hitung(u,val));
            }
        }
        ans = max(ans,mx+1);
        visited.assign(n+1,false);
    }
    cout << ans << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_sieve();

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
