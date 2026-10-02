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

    int n,m; cin >> n >> m;
    vector<ll> b(n+1),g(m+1);
    for(int i = 1; i <= n ; i++) cin >> b[i];
    for(int j = 1; j <= m ; j++) cin >> g[j];
    sort(b.begin()+1,b.end());
    sort(g.begin()+1,g.end());
    if(b[n] > g[1]){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> prefB(n+1,0);
    vector<ll> prefG(m+1,0);
    for(int i = 1; i <= n ; i++) prefB[i] = prefB[i-1] + b[i];
    for(int i = 1; i <= m ; i++) prefG[i] = prefG[i-1] + g[i];
    ll ans = 0;
    if(b[n] == g[1]){
        ans = m * prefB[n-1] + prefG[m];
    }
    else ans = prefB[n-2] * m + b[n-1] * (m-1) + g[m] + prefG[m-1] + b[n];
    cout << ans << endl; 

    return 0;
}
