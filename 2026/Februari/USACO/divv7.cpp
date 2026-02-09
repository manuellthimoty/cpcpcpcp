#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    ll n ; cin >> n;
    vector<ll> a(n+1,0);
    vector<ll> prefsum(n+1,0);
    for(ll i = 1 ;  i<= n ; i++) cin >> a[i];
    for(ll i = 1 ; i<= n ; i++){
        prefsum[i] = prefsum[i-1] + a[i];
    }
    vector<ll> mn(7,-1);
    vector<ll> mx(7,-1);
    for(ll i = 1 ; i<= n ; i++){
        ll k = prefsum[i] % 7;
        if(mn[k] == -1) mn[k] = i;
        else mn[k] = min(mn[k],i);
        if(mx[k] == -1) mx[k] = i;
        else mx[k] = max(mx[k],i);
    }
    ll ans = 0;
    for(ll i = 0 ; i < 7 ; i++){
        if(mn[i] == -1 || mx[i] == -1) continue;
        ans = max(ans,mx[i] - mn[i]);
    }
    freopen("div7.out", "w", stdout);
    cout << ans << endl;

    return 0;
}