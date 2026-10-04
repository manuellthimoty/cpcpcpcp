#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, x; cin >> n >> x;
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    
    map<ll, ll> lastIndex;  // map value → last index
    for(ll i = 1; i <= n; i++) {
        lastIndex[a[i]] = i;
    }
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = i+1; j <= n; j++) {  // j > i, avoid duplicate
            ll complement = x - a[i] - a[j];
            
            if(lastIndex.count(complement)) {
                ll k = lastIndex[complement];
                if(k != i && k != j) {
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}