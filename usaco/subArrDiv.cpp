#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> a(n+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    vector<ll> pref(n+1,0);
    vector<ll> count(n,0);
    count[0] ++;
    for(ll i = 1 ; i <= n ; i++){
        pref[i] = a[i] + pref[i-1];
        ll k = ((pref[i]  % n) + n) % n;
        count[k] ++;
    }
    ll ans = 0;
    for(auto x : count){
        ans += (x * (x-1))/2;
    }
    cout << ans << endl;

    return 0;
}