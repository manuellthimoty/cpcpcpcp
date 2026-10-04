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

    ll n,m; cin >> n >> m;
    vector<ll> x(n+1),y(m+1);
    for(int i = 1; i <= n ; i++) cin >> x[i];
    for(int i = 1; i <= m ; i++) cin >> y[i];
    ll q; cin >> q;
    vector<ll> pref_row(n+1,0),pref_col(m+1,0);
    for(int i = 1 ; i <= n ; i++){
        pref_row[i] = pref_row[i-1] ^ x[i];
    }
    for(int i = 1; i <= m ; i++){
        pref_col[i] = pref_col[i-1] ^ y[i];
    }
    
    while(q--){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        ll res_row = pref_row[b] ^ pref_row[a-1];
        ll res_col = pref_col[d] ^ pref_col[c-1];
        ll ans = res_row & res_col;
        cout << ans << '\n';
    }

    return 0;
}
