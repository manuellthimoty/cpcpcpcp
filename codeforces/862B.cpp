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
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n-1 ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> col(n+1,-1);
    queue<int> q;

    for(int i = 1 ; i <= n ; i++){
        if(col[i] == -1){
            q.push(i);
            col[i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(col[v] == -1){
                        col[v] = col[u] ^ 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    // for(int i = 1; i <= n ; i++) cout << col[i] << " ";

    ll cnt = 0;
    ll cnt0 = 0;
    ll cnt1 =0;

    if(col[1] == 0) cnt0++;
    else cnt1++;
    for(int i = 2; i <= n ; i++){
        if(col[i] == 1){
            cnt += cnt0;
            cnt1++;
        }
        else{
            cnt += cnt1;
            cnt0++;
        }
    }
    cout << cnt - n+1 << endl;
    return 0;
}
