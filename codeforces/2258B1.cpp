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

// 1 2 3 4 4
// 1 2 3 3 1 3 1
// 1 2 2 1 2 1 1 2 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> f(m+1,0);
    for(auto x: a) f[x]++;
    vector<ll> suff(m+2,0);
    for(int i = m ; i >= 0; i--){
        suff[i] = suff[i+1] + f[i];
    }
    ll ans = 0;
    // for(int i = 1 ; i <= m ; i++) cout << suff[i] << " ";
    for(int i = 1 ; i <= m ; i++){
        ll cur = suff[i];
        if(2 * i <= m) cur += f[2 * i];
        ans = max(ans,cur);
    }
    cout << ans << endl;
}
int main() {
    GK();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
