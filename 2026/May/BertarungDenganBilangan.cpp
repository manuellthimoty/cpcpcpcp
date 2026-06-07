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


/*
Observasi, perhatikan bahwa jika gcd(p,q) = y -> p = ya, q = yb dengan gcd(a,b) = 1
Dari sini, diperoleh bahwa lcm(p,q) * gcd(p,q) = pq -> x * y = ya * yb -> x = a * b * y
Dari sini, kita punya bahwa a *b = x/y. 
Ekuivalen dengan mencari a,b shg (a,b) = 1 dan a * b = x/y

*/
void solve(){
    int n ; cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];
    int m ; cin >> m;
    vector<int> c(m),d(m);

    for(int i = 0 ; i < m ; i++) cin >> c[i];
    for(int i = 0 ; i < m ; i++) cin >> d[i];

    vector<int> pn(2e6+5,0), pm(2e6+5,0);
    for(int i = 0 ; i < n ; i++){
        pn[a[i]] = b[i];
    }
    for(int i = 0 ; i < m ; i++){
        pm[c[i]] = d[i];
    }

    bool oks = true;
    // syarat y membagi x
    for(int i = 0 ; i < m ; i++){
        if(pm[c[i]] > pn[c[i]]){
            oks = false;
            cout << 0 << endl;
            return;
        }
    }
    for(int i = 0 ; i < n ; i++){
        pn[a[i]] -= pm[a[i]];
    }
    ll MOD = 998244353;
    ll ans = 1;
    for(int i = 0 ; i < n ; i++){
        if(pn[a[i]] > 0) ans *= 2;
        ans = ans % MOD;
    }
    cout << ans << endl;
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
