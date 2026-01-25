#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<ll,ll> freq;
    bool found = false;
    ll n ; cin >> n;
    for(ll i = 1 ; i<= n ; i++){
        ll nums; cin >> nums;
        freq[nums] = i;
    }
    ll ans = -1;
    for(ll i = 1 ; i <= n ; i++){
        if(!freq[i]){
            found = true;
            ans = i;
        }
    }
    if(true) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}