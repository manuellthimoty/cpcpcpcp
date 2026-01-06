#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n ; cin >> n ;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    ll sum = 0;
    for(ll i = 0 ; i < n-1 ; i++){
        ll abs = a[i]-a[i+1];
        if(abs<0) abs*=-1;
        sum += abs;
    }
    ll ans = 0;
    ll delFirst = a[0] - a[1];
    if (delFirst < 0) delFirst *= -1;
    ans = sum - delFirst;
    ll delLast = a[n-2] - a[n-1];
    if(delLast < 0) delLast *= -1;
    ans = min(ans,sum-delLast);
    for(ll i = 1 ; i < n - 1 ; i++){
        ll first = a[i-1] - a[i];
        if(first < 0) first *= -1;
        ll second = a[i] - a[i+1];
        if(second < 0) second *= -1;
        ll third = a[i-1] - a[i+1];
        if(third < 0) third *= -1;
        ll curr = first + second - third;
        ans = min(ans, sum - curr);
    }
    cout << ans << endl;
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