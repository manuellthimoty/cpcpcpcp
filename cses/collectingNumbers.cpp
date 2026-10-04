#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    unordered_map<ll,ll> index;
    for(ll i = 0 ; i < n ; i++) {
        ll nums ; cin >> nums;
        index[nums] = i;
    }
    ll ans = 1;
    for(ll i = 1 ; i < index.size() ; i++){
        if(index[i] < index[i-1]) ans++;
    }
    cout << ans << endl;
    

    return 0;
}