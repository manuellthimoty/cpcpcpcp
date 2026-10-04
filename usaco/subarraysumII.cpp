#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,x ; cin >> n >> x;
    vector<ll> a(n+1,0);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
    vector<ll> pref(n+1,0);
    for(ll i = 1 ; i <= n ; i++){
        pref[i] = a[i] + pref[i-1];
    }
    // mau jari indeks i, j shg i >= j dan pref[i] - pref[j] = x;
    map<ll,ll> count;
    ll ans = 0;
    count[0] = 1;
    for(ll i = 1 ; i <= n ; i++){
        ll complemen = pref[i] - x;
        ans += count[complemen];
        count[pref[i]]++;
    }
    cout << ans << endl;
    

    return 0;
}