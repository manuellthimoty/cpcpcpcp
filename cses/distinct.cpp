#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n; cin >> n;
    set<ll> s;
    
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(x);
    }
    
    cout << s.size() << endl;
    
    return 0;
}