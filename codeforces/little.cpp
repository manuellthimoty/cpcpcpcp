#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
void debug(ll val){
    cout << val << endl;
}
void solve() {
    ll n; cin >> n ;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    vector<ll> distinct(n);
    for(ll i = 0 ; i < n ; i++){
        distinct[i] = a[i];
    }
    sort(distinct.begin(), distinct.end());
    auto it = unique(distinct.begin(),distinct.end());
    distinct.erase(it,distinct.end());
    ll nunique = distinct.size();
    ll maksimum = *max_element(a.begin(),a.end());
    ll minimum = *min_element(a.begin(),a.end());
    for(auto x : distinct){
        if (nunique > x) {
            continue;;
        } 
        else {cout << x << endl; break;} 
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