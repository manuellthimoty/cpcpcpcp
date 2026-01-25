#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> divisorCount(1e6+5,0);
    for(ll i = 1 ; i < 1e6+4 ; i++){
        for(ll j = i ; j < 1e6+4 ; j+=i){
            divisorCount[j]++;
        }
    }
    int t;
    cin >> t;

    while (t--) {
        ll x ; cin >> x;
        cout << divisorCount[x] << endl;
    }

    return 0;
}