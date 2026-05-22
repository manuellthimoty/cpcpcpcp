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
// int curbfs = 0;
vector<int> curstate;
vector<bool> is_prime(MAX_VAL+1, true);

vector<ll> p(2e5+1,-1);

void precompute(){
    p[2] = 2;
    for(int i = 2 ; i <= 2e5 ; i+=2){
        p[i] = 2;
    }
    for(int i = 3 ; i <= 2e5 ; i+=2){
        if(p[i] == -1){
            for(int j = i ; j <= 2e5 ; j += i){
                if(p[j] == -1){
                    p[j] = i;
                }
            }
        }
        
    }
}

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
vector<ll> visited(n+1,0);
vector<ll> visited_prima(n+1,0);
ll curid = 0;
int hitung(int u, int prima){
    curid++;
    queue<int> q;
    // vector<int> distance(n+1,-1);
    distv[u] = 0;
    visited[u] = curid;
    visited_prima[u] = prima;
    q.push(u);
    // visited[u] = prima;
    
    int max_distance = 0;
    int terjauh = u;
    while(!q.empty()){
        int curr = q.front();
        visited[curr] = curid;
        q.pop();
        curstate[curr] = 1;
        for(int v : adj[curr]){
            if(a[v] % prima == 0 && visited[v] != curid){
                distv[v] = distv[curr] + 1;
                q.push(v);
                visited[v] = curid;
                visited_prima[v] = prima;
                curstate[v] = 1;
                if(distv[v] > max_distance){
                    max_distance = distv[v];
                    terjauh = v;
                }
            }
        }
    }
    // skrg udh punya terjauh, bfs sekali lagi
    curid++;
    int max_distance_2 = 0;
    int terjauh_2 = 0;      
    queue<int> q2;
    q2.push(terjauh);
    visited[terjauh] = curid;
    // distv.assign(n+1,-1);
    distv[terjauh] = 0;
    
    while(!q2.empty()){
        int curr = q2.front();
        visited[curr] = curid;
        q2.pop();
        curstate[curr] = 2;
        for(int v : adj[curr]){
            if(a[v] % prima == 0 && visited[v] != curid){
                distv[v] = distv[curr] + 1;
                q2.push(v);
                visited[v] = curid;
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
    // p.assign(n+1,0);
    visited.assign(n+1,0);
    visited_prima.assign(n+1,0);
    adj.assign(n+1,vector<int>());
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
        int last = 1;

        while(temp > 1){
            if(p[temp] != last){
                last = p[temp];
                nodeP[p[temp]].push_back(i);
            }
            temp = temp/p[temp];
        }
        // for(auto p : primes){
        //     if(temp % p == 0){
        //         nodeP[p].push_back(i);
        //         while(temp % p == 0){
        //             temp = temp/p;
        //         }
        //     }
        // }
    }
    vector<int> validP;
    for(int i = 1 ; i <= MAX_VAL ; i++){
        if(nodeP[i].size() > 0){
            validP.push_back(i);
        }
    }
    for(auto val : validP){
        // cout << "Prima skrg: " << val << " : ";
        // val : nodeP[val] sizenya > 0
        vector<ll> curList = nodeP[val];
        // for(auto x : curList) cout << x << " ";
        int mx = 0;
        for(auto u : curList){
            if(visited_prima[u] != val){
                mx = max(mx, hitung(u,val));
            }
        }
        ans = max(ans,mx+1);
        // visited.assign(n+1,false);
    }
    cout << ans << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // build_sieve();
    precompute();

    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
