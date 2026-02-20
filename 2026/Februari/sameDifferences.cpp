#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n ; cin >> n;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    vector<ll> p(n);
    for(ll i = 0 ; i < n ; i++) p[i] = a[i] - i;
    map<ll,ll> count;
    for(ll i = 0 ; i < n ; i++){
        count[p[i]] ++ ;
    }
    ll sum = 0;
    for(auto x : count){
        sum += (x.second * (x.second - 1))/2;
    }
    cout << sum << endl;
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
