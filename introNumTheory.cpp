#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool aman(ll val, ll comp){
    return (val % comp == 0 || comp % val == 0);
          
}

void solve() {
    ll n ; cin >> n ;
    vector<ll> a(n);
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    vector<ll> divisors;
    ll maxVal = -1;
    for(ll i = 0 ; i < n  ; i++) maxVal = max(maxVal,a[i]);
    for(ll i = 1 ; i * i <= maxVal ; i++){
        if(maxVal % i == 0){
            divisors.push_back(i);
            divisors.push_back(maxVal/i);
        }
    }
    for(auto d : divisors){
        ll countMult = 0;
        ll countDiv = 0;
        ll found = true;
        for(ll i = 0 ; i < n ; i++){
            if(!aman(d,a[i])) {
                found = false;
                break;
            };
            if(d % a[i] == 0) countMult++;
            if(a[i] % d == 0) countDiv ++;
        }
        if(!found) continue;
        if(countMult >=1 && countDiv >=1){
            cout << d << endl;
            return;
        }
    }
    cout << -1 << endl;
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