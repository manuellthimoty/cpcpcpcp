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

void solve(){
    int n,m ; cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            cin >> a[i][j];
        }
    }
    map<int,vector<int>> xs;
    map<int,vector<int>> ys;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            int cur = a[i][j];
            xs[cur].push_back(i);
            ys[cur].push_back(j);
        }
    }
    for(auto t : xs){
        sort(t.second.begin(),t.second.end());
    }
    for(auto t : ys){
        sort(t.second.end(),t.second.end());
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
